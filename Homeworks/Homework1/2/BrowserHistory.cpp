#include<iostream>

#include "BrowserHistory.h"

BrowserHistory::BrowserHistory()
{
	m_numberOfWebsite = nullptr;
	m_n = 0;
	m_websiteCount = 0;
}

BrowserHistory::BrowserHistory(int N)
{
	/* N is a memory of the browser*/
	if (N > 0)
	{
		m_numberOfWebsite = new HistoryEntry[N];
		m_n = N;
		m_websiteCount = 0;
	}
	else 
	{
		std::cout << "The number can't be negative!" << std::endl;
	}
}

BrowserHistory::BrowserHistory(const BrowserHistory & b)
{
	CopyFrom(b);
}

BrowserHistory BrowserHistory::operator=(const BrowserHistory & b)
{
	if (this != &b)
	{
		Destroy();
		CopyFrom(b);
	}
	return *this;
}

void BrowserHistory::AddNewWebSite()
{
	if (CheckMemoryIsFull() == false)
	{
		int month;
		char* url = new char[DEFAUT_SIZE_OF_URL];
		std::cout << "Enter month: ";
		std::cin >> month;
		std::cout << "Enter url: ";
		std::cin >> url;
		HistoryEntry h(month, url);
		m_numberOfWebsite[m_websiteCount] = h;
		m_websiteCount++;
		if (m_websiteCount - 1 > 0)
		{
			SortWebsitesByMonth(m_numberOfWebsite);
		}
	}
	else
	{
		std::cout << "Can't add new website!The memory is full!" << std::endl;
	}
}

void BrowserHistory::AddNewWebSite(const HistoryEntry &h)
{
	if (CheckMemoryIsFull() == false)
	{
		m_numberOfWebsite[m_websiteCount] = h;
		m_websiteCount++;
		if (m_websiteCount - 1 > 0)
		{
			SortWebsitesByMonth(m_numberOfWebsite);
		}
	}
	else
	{
		std::cout << "Can't add new website!The memory is full!" << std::endl;
	}
}

void BrowserHistory::PrintAllWebsites() const
{
	if (IsEmpty() == false)
	{
		for (int i = 0; i < m_websiteCount; i++)
		{
			std::cout << "URL of website: "<<m_numberOfWebsite[i].m_url<<" "<<" is visited in: "<< m_numberOfWebsite[i].m_month<<" month" << std::endl;
		}
	}
	else
	{
		std::cout << "Can't print all websites!The history is empty!" << std::endl;
	}
}

int BrowserHistory::FindWebsiteByMonth(int month) const
{
	if (month > 0 && month < 13)
	{
		int count = 0;
		for (int i = 0; i < m_websiteCount; i++)
		{
			if (m_numberOfWebsite[i].m_month == month)
			{
				count++;
			}
		}
		return count;
	}
	else
	{
		std::cout << "Invalide month!" << std::endl;
		return 0;
	}
}

int BrowserHistory::FindMostVisitedWebsiteByMonth() const
{
	if (IsEmpty() == false)
	{
		int month = m_numberOfWebsite[0].m_month;
		int maxMonth = month;
		int count = 1;
		int maxCount = 0;
		for (int i = 1; i <= m_websiteCount - 1; i++)
		{
			if (month == m_numberOfWebsite[i].m_month)
			{
				count++;
			}
			else
			{
				if (count > maxCount)
				{
					maxCount = count;
					maxMonth = month;
				}
				month = m_numberOfWebsite[i].m_month;
				count = 0;
			}
		}
		return maxMonth;
	}
	else
	{
		std::cout << "The history is empty!" << std::endl;
	}
}

void BrowserHistory::RemoveRecentlyAddedSite()
{
	if (m_websiteCount - 1 >= 0)
	{
		HistoryEntry * arr = new HistoryEntry[m_websiteCount - 1];
		for (int i = 0; i < m_websiteCount - 1; i++)
		{
			arr[i].m_month = m_numberOfWebsite[i].m_month;
			arr[i].m_url = m_numberOfWebsite[i].m_url;
		}
		Destroy();
		m_websiteCount--;
		m_numberOfWebsite = arr;
	}
	else
	{
		std::cout << "Can't remove site!The history is empty!" << std::endl;
	}
}

BrowserHistory BrowserHistory::operator+(const BrowserHistory & b)
{
	BrowserHistory unionObjects(m_websiteCount + b.m_websiteCount);
	for (int i = 0; i < m_websiteCount; i++)
	{
		unionObjects.AddNewWebSite(m_numberOfWebsite[i]);
	}
	for (int i = 0; i < b.m_websiteCount; i++)
	{
		unionObjects.AddNewWebSite(b.m_numberOfWebsite[i]);
	}
	return unionObjects;
}

BrowserHistory::~BrowserHistory()
{
	Destroy();
}

/*Bubble sort*/
void BrowserHistory::SortWebsitesByMonth(HistoryEntry *h) 
{
	int temp, len, len1;
	char *u;
	for (int i = 0; i < m_websiteCount - 1; i++)
	{
		for (int j = 0; j < m_websiteCount - i - 1; j++)
		{
			if (h[j].m_month > h[j + 1].m_month)
			{
				temp = h[j].m_month;
				len = strlen(h[j].m_url);
				u = new char[len + 1];
				strcpy_s(u, len + 1, h[j].m_url);

				h[j].m_month = h[j + 1].m_month;
				len1 = strlen(h[j + 1].m_url);
				h[j].m_url = new char[len1 + 1];
				strcpy_s(h[j].m_url, len1 + 1, h[j + 1].m_url);

				h[j + 1].m_month = temp;
				h[j + 1].m_url = new char[len + 1];
				strcpy_s(h[j + 1].m_url, len + 1, u);
			}
		}
	}
}

void BrowserHistory::CopyFrom(const BrowserHistory &h)
{
	m_n = h.m_n;
	m_websiteCount = h.m_websiteCount;
	m_numberOfWebsite = new HistoryEntry[m_n];
	for (int i = 0; i < m_websiteCount; i++)
	{
		m_numberOfWebsite[i].m_month = h.m_numberOfWebsite[i].m_month;
		m_numberOfWebsite[i].m_url = h.m_numberOfWebsite[i].m_url;
	}
}

bool BrowserHistory::IsEmpty() const
{
	if (m_websiteCount >= 0)
	{
		return false;
	}
	return true;
}

bool BrowserHistory::CheckMemoryIsFull() const
{
	if (m_websiteCount < m_n)
	{
		return false;
	}
	return true;
}

void BrowserHistory::Destroy()
{
	delete[] m_numberOfWebsite;
}