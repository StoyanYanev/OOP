#ifndef SETTINGS_H
#define SETTINGS_H

#include<iostream>

#include "Pair.h"

template<typename T>
class Settings
{
public:
	Settings();
	Settings(const Settings&s);
	Settings<T> &operator=(const Settings&s);
	int Count()const;
	void Set(const char* key, T val);
	bool Get(const char* key, T& val)const;
	void Print()const;
	~Settings();

private:
	void CopyFrom(const Settings&s);
	void Destroy();
	void Resize();
	bool IsFull()const;

	enum { MAX_SIZE = 50 };
	Pair<T>* m_pair;
	int m_index;
	int m_size;
};

template<typename T>
inline Settings<T>::Settings()
{
	m_index = 0;
	m_size = MAX_SIZE;
	m_pair = new Pair<T>[m_size];
}

template<typename T>
inline Settings<T>::Settings(const Settings& s)
{
	CopyFrom(s);
}

template<typename T>
inline Settings<T>& Settings<T>::operator=(const Settings& s)
{
	if (this != &s)
	{
		Destroy();
		CopyFrom(s);
	}
	return *this;
}

template<typename T>
inline int Settings<T>::Count() const
{
	return m_index;
}

template<typename T>
inline void Settings<T>::Set(const char * key, T val)
{
	if (IsFull() == true)
	{
		Resize();
	}
	bool isFind = false;
	for (int i = 0; i < m_index; i++)
	{
		if (strcmp(m_pair[i].GetKey(), key) == 0)
		{
			m_pair[i].SetValue(val);
			isFind = true;
		}
	}
	if (isFind == false)
	{
		m_pair[m_index].SetKey(key);
		m_pair[m_index].SetValue(val);
		m_index++;
	}
}

template<typename T>
inline bool Settings<T>::Get(const char* key, T& val)const
{
	for (int i = 0; i < m_index; i++)
	{
		if (strcmp(m_pair[i].GetKey(), key) == 0)
		{
			val = m_pair[i].GetValue();
			return true;
		}
	}
	return false;
}

template<typename T>
inline void Settings<T>::Print() const
{
	for (int i = 0; i < m_index; i++)
	{
		std::cout << "Key: " << m_pair[i].GetKey() << " Value: " << m_pair[i].GetValue() << std::endl;
	}
}

template<typename T>
inline Settings<T>::~Settings()
{
	Destroy();
}

template<typename T>
inline void Settings<T>::CopyFrom(const Settings& s)
{
	m_index = s.m_index;
	m_size = s.m_size;
	m_pair = new Pair<T>[m_size];
	for (int i = 0; i < m_index; i++)
	{
		m_pair[i].SetKey(s.m_pair[i].GetKey());
		m_pair[i].SetValue(s.m_pair[i].GetValue());
	}
}

template<typename T>
inline void Settings<T>::Destroy()
{
	delete[] m_pair;
}

template<typename T>
inline void Settings<T>::Resize()
{
	m_size = MAX_SIZE * 2;
	Pair<T> *newPair = new Pair<T>[m_size];
	for (int i = 0; i < m_index; i++)
	{
		newPair[i].SetKey(m_pair[i].GetKey());
		newPair[i].SetValue(m_pair[i].GetValue());
	}
	Destroy();
	m_pair = newPair;
}

template<typename T>
inline bool Settings<T>::IsFull() const
{
	if (m_index + 1 >= m_size)
	{
		return true;
	}
	return false;
}
#endif