#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task 
{
    string description;
    bool completed;

    Task(const string& desc):description(desc),completed(false){}
};

void displayMenu() 
{
    cout<< "\nTo-Do List Manager\n";
    cout<< "1. Add Task\n";
    cout<< "2. View Tasks\n";
    cout<< "3. Mark Task as Completed\n";
    cout<< "4. Delete Task\n";
    cout<< "5. Exit\n";
}

void addTask(vector<Task>& tasks) 
{
    cout<< "Enter a new task:";
    string description;
    cin.ignore();
    getline(cin, description);
 	tasks.push_back(Task(description));
    cout<< "Task added.\n";
}

void viewTasks(const vector<Task>& tasks) 
{
    if (tasks.empty()) 
	{
    cout<<"No tasks to show.\n";
    } 
	else 
	{
        cout<<"\nTasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) 
		{
            cout<<i+1<<". "<< tasks[i].description<<" ["<<(tasks[i].completed ?"Completed":"Pending")<<"]\n";
        }
    }
}

void markTaskCompleted(vector<Task>& tasks) 
{
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout<< "Enter the task number to mark as completed: ";
    size_t taskNum;
    cin>>taskNum;

    if (taskNum>0 && taskNum<=tasks.size()) 
	{
        tasks[taskNum-1].completed=true;
        cout<<"Task marked as completed.\n";
    } 
	else 
	{
        cout<<"Invalid task number.\n";
    }
}

void deleteTask(vector<Task>& tasks) 
{
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout<<"Enter the task number to delete: ";
    size_t taskNum;
    cin>>taskNum;

    if (taskNum>0 && taskNum<=tasks.size()) 
	{
        tasks.erase(tasks.begin()+taskNum - 1);
        cout<<"Task deleted.\n";
    } 
	else 
	{
        cout<<"Invalid task number.\n";
    }
}

int main() 
{
	vector<Task> tasks;
    int choice;

    do 
	{
        displayMenu();
        cout<<"Choose an option (1-5): ";
        cin>>choice;

        switch (choice) 
		{
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout<<"Exiting the To-Do List Manager.\n";
                break;
            default:
                cout<<"Invalid choice. Please choose a number between 1 and 5.\n";
        }
    } 
	while (choice!=5);

    return 0;
}

