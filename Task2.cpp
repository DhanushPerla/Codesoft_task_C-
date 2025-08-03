#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool completed;
};

void addTask(vector<Task>& tasks) {
    string taskName;
    cout << "Enter task name: ";
    cin.ignore();
    getline(cin, taskName);
    tasks.push_back({taskName, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "\n--- Task List ---\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void markCompleted(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as completed: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed successfully!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    do {
        cout<<"\n--- TO-DO LIST MENU ---\n";
        cout<<"1. Add Task\n";
        cout<<"2. View Tasks\n";
        cout<<"3. Mark Task as Completed\n";
        cout<<"4. Remove Task\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks);
            break;
            case 2: viewTasks(tasks); 
            break;
            case 3: markCompleted(tasks);
            break;
            case 4: removeTask(tasks);
            break;
            case 5: cout << "Exiting...";
            break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);
    return 0;
}
