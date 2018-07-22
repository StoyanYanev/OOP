#include <iostream>

#include "HistoryEntry.h"

HistoryEntry::HistoryEntry() 
{
	m_month = 0;
	m_url = '\0';
}
HistoryEntry::HistoryEntry(int month, const char * url)
{
	if (month > 0 && month <= 12)
	{
		m_month = month;
		int len = strlen(url);
		m_url = new char[len + 1];
		strcpy_s(m_url, len + 1, url);
	}
	else
	{
		std::cout << "Invalide month!" << std::endl;
	}
}