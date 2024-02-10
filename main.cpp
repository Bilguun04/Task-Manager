#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string name;
    string description;
    bool completed;
};

class TaskManager {
private:
    vector<Task> tasks;

public:
    void addTask(const string& name, const string& description) {
        Task task = {name, description, false};
        tasks.push_back(task);
        cout << "Task added successfully!" << endl;
    }

    void markTaskAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void displayTasks() {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].name << " - " << tasks[i].description << endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        cout << "Task Manager Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, description;
                cout << "Enter task name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, name);
                cout << "Enter task description: ";
                getline(cin, description);
                taskManager.addTask(name, description);
                break;
            }
            case 2: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                taskManager.markTaskAsCompleted(index - 1);
                break;
            }
            case 3: {
                taskManager.displayTasks();
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
