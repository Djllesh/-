#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using namespace std;


TaskStatus Next(TaskStatus task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
	void RemoveZeros(TasksInfo& check) {
	  // Соберём те статусы, которые нужно убрать из словаря
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
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;

  // Добавить новую задачу (в статусе NEW) для конкретного разработчика
  void AddNewTask(const string& person);

  // Обновить статусы по данному количеству задач конкретного разработчика
  
	tuple<TasksInfo, TasksInfo> PerformPersonTasks(
		const string& person, int task_count) {
	  TasksInfo updated_tasks, untouched_tasks;
	  
	  
	  TasksInfo& tasks = person_tasks_[person];

	  
	  for (TaskStatus status = TaskStatus::NEW;
		   status != TaskStatus::DONE;
		   status = Next(status)) {
		// Считаем обновлённые
		updated_tasks[Next(status)] = min(task_count, tasks[status]);
		// Считаем, сколько осталось обновить
		task_count -= updated_tasks[Next(status)];
	  }

	  // Обновляем статус текущих задач в соответствии с информацией об обновлённых 
	  // и находим количество нетронутых
	  for (TaskStatus status = TaskStatus::NEW;
		   status != TaskStatus::DONE;
		   status = Next(status)) {
		untouched_tasks[status] = tasks[status] - updated_tasks[Next(status)];
		tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
	  }
	  // По условию DONE задачи не нужно вовзвращать в не обновлённых задачах
	  tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

	  // По условию в словарях не должно быть нулей
	  RemoveZeros(updated_tasks);
	  RemoveZeros(untouched_tasks);
	  RemoveZeros(person_tasks_[person]);

	  return {updated_tasks, untouched_tasks};
	}
private:
  map<string, TasksInfo> person_tasks_;
};

const TasksInfo& TeamTasks::GetPersonTasksInfo(const string& person) const {
  return person_tasks_.at(person);
}

void TeamTasks::AddNewTask(const string& person) {
  ++person_tasks_[person][TaskStatus::NEW];
}

// Функция для удаления нулей из словаря



