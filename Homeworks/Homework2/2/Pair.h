#ifndef PAIR_H
#define PAIR_H

#include<iostream>

template<typename T>
class Pair
{
public:
	Pair();
	Pair(const char* key, T val);
	Pair(const Pair&p);
	Pair<T> &operator=(const Pair&p);
	void SetKey(const char * key);
	void SetValue(T val);
	const char * GetKey()const;
	T GetValue()const;
	~Pair();
private:
	void CopyFrom(const Pair&p);
	void Destroy();

	char* m_key;
	T m_val;
};

template<typename T>
inline Pair<T>::Pair()
{
	this->SetKey("");
}

template<typename T>
inline Pair<T>::Pair(const char * key, T val)
{
	this->SetKey(key);
	this->SetValue(val);
}

template<typename T>
inline Pair<T>::Pair(const Pair & p)
{
	CopyFrom(p);
}

template<typename T>
inline Pair<T> & Pair<T>::operator=(const Pair & p)
{
	if (this != &p)
	{
		Destroy();
		CopyFrom(p);
	}
	return *this;
}

template<typename T>
inline void Pair<T>::SetKey(const char * key)
{
	int l = strlen(key);
	m_key = new char[l + 1];
	strcpy_s(m_key, l + 1, key);
}

template<typename T>
inline void Pair<T>::SetValue(T val)
{
	m_val = val;
}

template<typename T>
inline const char * Pair<T>::GetKey() const
{
	return m_key;
}

template<typename T>
inline T Pair<T>::GetValue() const
{
	return m_val;
}

template<typename T>
inline Pair<T>::~Pair()
{
	Destroy();
}

template<typename T>
inline void Pair<T>::CopyFrom(const Pair & p)
{
	this->SetKey(p.GetKey());
	this->SetValue(p.GetValue());
}

template<typename T>
inline void Pair<T>::Destroy()
{
	delete[] m_key;
}
#endif