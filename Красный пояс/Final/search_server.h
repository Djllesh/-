#pragma once
#include <istream>
#include <vector>
#include <unordered_map>
#include <string>
#include <future>
#include "synchronized.h"

using namespace std; 
class InvertedIndex
{
public:
	InvertedIndex() = default;

	explicit InvertedIndex(istream& document_input);

	const vector<pair<size_t, size_t>>& Lookup(const string& word) const;

	size_t GetDocsCount() const
	{
		return docs_count_;
	}

private:
	size_t docs_count_ = 0;
	unordered_map<string, vector<pair<size_t, size_t>>> index;
};


class SearchServer
{
public:
	SearchServer() = default;

	explicit SearchServer(istream& document_input)
		: index_(InvertedIndex(document_input)) {}

	void UpdateDocumentBase(istream& document_input);

	void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
	Synchronized<InvertedIndex> index_;
	vector<future<void>> futures_;
};