#include <iomanip>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <map>
#include <queue>
#include <unordered_map>
#include "profile.h"
using namespace std;
constexpr int DAY_SECONDS = 86400;

struct HotelManager
{
	int64_t time = 0;
	string hotel_name;
	uint32_t client_id = 0;
	uint32_t room_count = 0;
};


class HotelManagerSystem
{
public:
	HotelManagerSystem() = default;
	void Book(const HotelManager& hotel_manager)
	{
		client_base.push(hotel_manager);
		clients[hotel_manager.hotel_name][hotel_manager.client_id] += hotel_manager.room_count;
		rooms[hotel_manager.hotel_name] += hotel_manager.room_count;
		Adjust(hotel_manager.time);
	}

	uint64_t GetClients(const string& hotel_name)
	{
		return clients[hotel_name].size();
	}

	int GetRooms(const string& hotel_name)
	{
		if(rooms.find(hotel_name) != rooms.end()) return rooms[hotel_name];
		return 0; 
	}

private:

	void Adjust(const int64_t time)
	{
		while (!client_base.empty() && client_base.front().time + DAY_SECONDS <= time)
		{
			auto first = client_base.front();
			client_base.pop();
			clients[first.hotel_name][first.client_id] -= first.room_count;
			if (clients[first.hotel_name][first.client_id] == 0)
				clients[first.hotel_name].erase(first.client_id);
			rooms[first.hotel_name] -= first.room_count;
		}
	}
	queue<HotelManager> client_base;
	map<string, map<uint32_t, uint32_t>> clients;
	map<string, int> rooms;
};

int main()
{
	HotelManagerSystem client_base;
	int q;
	cin >> q;
	string query_type;
	for (int i = 0; i < q; i++)
	{
		cin >> query_type;
		string hotel_name;
		if (query_type == "BOOK")
		{
			int64_t time;
			uint32_t client_id;
			uint32_t room_count;
			cin >> time >> hotel_name
				>> client_id >> room_count;
			client_base.Book({ time , hotel_name , client_id , room_count });
		}
		else if (query_type == "ROOMS")
		{
			string hotel_name; 
			cin >> hotel_name;
			cout << client_base.GetRooms(hotel_name) << endl;
		}
		else if (query_type == "CLIENTS")
		{
			string hotel_name;
			cin >> hotel_name;
			cout << client_base.GetClients(hotel_name) << endl;
		}
	}
	return 0;
}