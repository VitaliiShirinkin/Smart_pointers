//ќписание:
//Ќужно создать упрощЄнный аналог std::unique_ptr.
//¬ шаблонном классе должны быть реализованы функции :
// -  онструктор, принимающий сырой указатель.
// - ѕерегружен оператор* дл€ получени€ объекта.
// - «апрещены оператор присваивани€ и конструктор копировани€.
// - ћетод release, который освобождает владение и возвращает сырой указатель.
// - ƒеструктор.
#pragma once

template<class T>
class unique_ptr
{
	T* u_ptr = nullptr;
public:
	unique_ptr<T>(T*ptr) {
		this->u_ptr = ptr;
	}

	//оператор копирующего присваивани€
	unique_ptr<T>& operator = (const unique_ptr& other) = delete;

	//конструктор копировани€
	unique_ptr<T>(const unique_ptr& other) = delete;

	//конструктор перемещени€
	unique_ptr<T>(unique_ptr&& other) noexcept {
		this->u_ptr = other.u_ptr;
		other.u_ptr = nullptr;
	}

	//оператор перемещающего присваивани€
	unique_ptr<T>& operator = (unique_ptr&& other) noexcept {
		if (this != other) {
			delete this->u_ptr;
			this->u_ptr = other.u_ptr;
			other.u_ptr = nullptr;
		}
		return *this;
	}

	//деструктор
	~unique_ptr<T>() {
		u_ptr = nullptr;
	}
	 //ћетод release, который освобождает владение и возвращает сырой указатель
	T* release() {
		T* tmp = u_ptr;
		u_ptr = nullptr;
		return tmp;
	}

	//оператор разыменовани€ указател€
	T& operator *() const {
		return *u_ptr;
	}
};
