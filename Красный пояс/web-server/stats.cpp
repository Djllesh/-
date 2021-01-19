#include "stats.h"

Stats::Stats()
{
	method_stats = {
				{"GET", 0},
				{"PUT", 0},
				{"POST", 0},
				{"DELETE", 0},
				{"UNKNOWN", 0}
	};

	uri_stats = {
				{"/", 0},
				{"/order", 0},
				{"/product", 0},
				{"/basket", 0},
				{"/help", 0},
				{"unknown", 0}
	};
}

void Stats::AddMethod(string_view method)
{
	if (method != "GET" && method != "PUT" && method != "POST" && method != "DELETE")
	{
		++method_stats["UNKNOWN"];
	}
	else
	{
		++method_stats[method];
	}
}

void Stats::AddUri(string_view uri)
{
	if (uri != "/" && uri != "/order" && uri != "/product" && uri != "/basket" && uri != "/help")
	{
		++uri_stats["unknown"];
	}
	else ++uri_stats[uri];
}

const map<string_view, int>& Stats::GetMethodStats() const
{
	return method_stats;
}

const map<string_view, int>& Stats::GetUriStats() const
{
	return uri_stats;
}

HttpRequest ParseRequest(string_view line)
{
	HttpRequest result;
	auto pos = line.find_first_not_of(' ');
	line.remove_prefix(pos);
	size_t method_pos = line.find(" ");
	result.method = line.substr(0, method_pos);
	line.remove_prefix(method_pos + 1);
	size_t uri_pos = line.find(" ");
	result.uri = line.substr(0, uri_pos);
	line.remove_prefix(uri_pos + 1);
	result.protocol = line;
	return result;
}