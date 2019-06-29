#pragma once
#include <functional>



template<class Param, class ...Args>
struct callback_parameter final {

	using function_type = std::function<BOOL(Param, Args...)>;
	using parameter_type = Param;

	function_type function;
	parameter_type parameter;

	explicit callback_parameter(function_type func) : function(func), parameter() {}

	callback_parameter(function_type func, parameter_type param) : function(func), parameter(param) {}
	
	static BOOL CALLBACK callback_invoke_lambda(Args...args, LPARAM l_param) {
		callback_parameter<Param, Args...>* param = reinterpret_cast<callback_parameter<Param, Args...>*>(l_param);
		return param->function(param->parameter, args...);
	}

};