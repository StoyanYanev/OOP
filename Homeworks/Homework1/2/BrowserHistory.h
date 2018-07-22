#ifndef BROWSER_HISTORY_H
#define BROWSER_HISTORY_H

#include "HistoryEntry.h"

class BrowserHistory
{
public:
	BrowserHistory();
	BrowserHistory(int N);
	BrowserHistory(const BrowserHistory& b);
	BrowserHistory operator=(const BrowserHistory& b);
	void AddNewWebSite();
	void AddNewWebSite(const HistoryEntry &h);
	void PrintAllWebsites() const;
	int FindWebsiteByMonth(int month) const;
	int FindMostVisitedWebsiteByMonth() const;
	void RemoveRecentlyAddedSite();
	BrowserHistory operator+(const BrowserHistory &b); /*concatenate two object from BrowserHistory*/
	~BrowserHistory();
private:
	void SortWebsitesByMonth(HistoryEntry *h); /*sorted entered sites by month*/
	void CopyFrom(const BrowserHistory &h);
	bool IsEmpty() const;
	bool CheckMemoryIsFull() const;
	void Destroy();

	enum { DEFAUT_SIZE_OF_URL = 50 };
	HistoryEntry * m_numberOfWebsite;
	int m_n; /* momory of the browser*/
	int m_websiteCount; /*number of the added websites*/
};
#endif