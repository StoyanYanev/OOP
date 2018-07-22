#ifndef HISTORY_ENTRY_H
#define HISTORY_ENTRY_H

struct HistoryEntry
{
	int m_month;
	char* m_url;
	HistoryEntry();
	HistoryEntry(int month, const char *url);
};
#endif