// Реализуйте функции и методы классов и при необходимости добавьте свои
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <exception>
#include <sstream>
#include <tuple>
using namespace std;
enum class TaskStatus 
{
	NEW,          // новая
	IN_PROGRESS,  // в разработке
	TESTING,      // на тестировании
	DONE          // завершена
};

using TasksInfo = map<TaskStatus, int>;

class TeamTasks 
{
public:

	// Получить статистику по статусам задач конкретного разработчика
	const TasksInfo& GetPersonTasksInfo(const string& person) const
	{
	
		auto it = team.find(person);
		if (it != end(team)) return it->second;
		else return {};
	}
	// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
	void AddNewTask(const string& person)
	{
		++team[person][TaskStatus::NEW];
	}

	// Обновить статусы по данному количеству задач конкретного разработчика,
	// подробности см. ниже
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
	{
		//проверяем запрос на максимальное количество задач
		int undone_tasks = team[person][TaskStatus::NEW] + team[person][TaskStatus::IN_PROGRESS] + team[person][TaskStatus::TESTING];
		if (task_count > undone_tasks)
		{
			task_count = undone_tasks;
		}
		TasksInfo updated, untouched;
		if (team.count(person) > 0)
		{
			if (task_count - team[person][TaskStatus::NEW] >= 0 && task_count != 0)
			{
				task_count -= team[person][TaskStatus::NEW];
				updated[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::NEW];
				team[person].erase(TaskStatus::NEW);
				if (task_count - team[person][TaskStatus::IN_PROGRESS] >= 0 && task_count != 0)
				{
					task_count -= team[person][TaskStatus::IN_PROGRESS];
					updated[TaskStatus::TESTING] = team[person][TaskStatus::IN_PROGRESS];
					team[person].erase(TaskStatus::IN_PROGRESS);
					if (task_count - team[person][TaskStatus::TESTING] == 0 && task_count != 0)
					{
						updated[TaskStatus::DONE] = team[person][TaskStatus::TESTING];
						team[person].erase(TaskStatus::TESTING);
						team[person][TaskStatus::DONE] += updated[TaskStatus::DONE];
						return tie(updated, untouched);
					}
					else
					{
						updated[TaskStatus::DONE] = task_count;
						untouched[TaskStatus::TESTING] = team[person][TaskStatus::TESTING] - task_count;
						team[person][TaskStatus::TESTING] = untouched[TaskStatus::TESTING] + updated[TaskStatus::TESTING];
						team[person][TaskStatus::DONE] += updated[TaskStatus::DONE];
						DeleteZeroes(updated);
						DeleteZeroes(untouched);
						return tie(updated, untouched);
					}
				}
				else
				{
					updated[TaskStatus::TESTING] = task_count;
					untouched[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::IN_PROGRESS] - task_count;
					team[person][TaskStatus::IN_PROGRESS] = untouched[TaskStatus::IN_PROGRESS] + updated[TaskStatus::IN_PROGRESS];
					untouched[TaskStatus::TESTING] = team[person][TaskStatus::TESTING];
					team[person][TaskStatus::TESTING] += updated[TaskStatus::TESTING];
					DeleteZeroes(updated);
					DeleteZeroes(untouched);
					return tie(updated, untouched);
				}
			}
			else
			{
				updated[TaskStatus::IN_PROGRESS] = task_count;
				untouched[TaskStatus::NEW] = team[person][TaskStatus::NEW] - task_count;
				team[person][TaskStatus::NEW] = untouched[TaskStatus::NEW] + updated[TaskStatus::NEW];
				untouched[TaskStatus::IN_PROGRESS] = team[person][TaskStatus::IN_PROGRESS];
				team[person][TaskStatus::IN_PROGRESS] += updated[TaskStatus::IN_PROGRESS];
				untouched[TaskStatus::TESTING] = team[person][TaskStatus::TESTING];
				DeleteZeroes(updated);
				DeleteZeroes(untouched);
				return tie(updated, untouched);
			}
		}
		return tie(updated, untouched);
	}
private:
	void DeleteZeroes(TasksInfo& check)
	{
		if (check[TaskStatus::NEW] == 0)
		{
			check.erase(TaskStatus::NEW);
		}
		if (check[TaskStatus::IN_PROGRESS] == 0)
		{
			check.erase(TaskStatus::IN_PROGRESS);
		}
		if (check[TaskStatus::TESTING] == 0)
		{
			check.erase(TaskStatus::TESTING);
		}
		if (check[TaskStatus::DONE] == 0)
		{
			check.erase(TaskStatus::DONE);
		}
	}
	map<string, TasksInfo> team;
	
};
void PrintTasksInfo(TasksInfo tasks_info) {
	cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
		", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
		", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
		", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
	TeamTasks tasks;
	tasks.AddNewTask("Ilia");
	for (int i = 0; i < 3; ++i) {
		tasks.AddNewTask("Ivan");
	}
	cout << "Ilia's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
	cout << "Ivan's tasks: ";
	PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

	TasksInfo updated_tasks, untouched_tasks;

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);

	tie(updated_tasks, untouched_tasks) =
		tasks.PerformPersonTasks("Ivan", 2);
	cout << "Updated Ivan's tasks: ";
	PrintTasksInfo(updated_tasks);
	cout << "Untouched Ivan's tasks: ";
	PrintTasksInfo(untouched_tasks);
	PrintTasksInfo(tasks.GetPersonTasksInfo("Andtr"));
	return 0;
}