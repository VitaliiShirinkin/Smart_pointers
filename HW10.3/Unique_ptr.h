//��������:
//����� ������� ���������� ������ std::unique_ptr.
//� ��������� ������ ������ ���� ����������� ������� :
// - �����������, ����������� ����� ���������.
// - ���������� ��������* ��� ��������� �������.
// - ��������� �������� ������������ � ����������� �����������.
// - ����� release, ������� ����������� �������� � ���������� ����� ���������.
// - ����������.
#pragma once

template<class T>
class unique_ptr
{
	T* u_ptr = nullptr;
public:
	unique_ptr<T>(T*ptr) {
		this->u_ptr = ptr;
	}

	//�������� ����������� ������������
	unique_ptr<T>& operator = (const unique_ptr& other) = delete;

	//����������� �����������
	unique_ptr<T>(const unique_ptr& other) = delete;

	//����������� �����������
	unique_ptr<T>(unique_ptr&& other) noexcept {
		this->u_ptr = other.u_ptr;
		other.u_ptr = nullptr;
	}

	//�������� ������������� ������������
	unique_ptr<T>& operator = (unique_ptr&& other) noexcept {
		if (this != other) {
			delete this->u_ptr;
			this->u_ptr = other.u_ptr;
			other.u_ptr = nullptr;
		}
		return *this;
	}

	//����������
	~unique_ptr<T>() {
		u_ptr = nullptr;
	}
	 //����� release, ������� ����������� �������� � ���������� ����� ���������
	T* release() {
		T* tmp = u_ptr;
		u_ptr = nullptr;
		return tmp;
	}

	//�������� ������������� ���������
	T& operator *() const {
		return *u_ptr;
	}
};
