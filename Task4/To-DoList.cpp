#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool done;
};

void addTask(vector<Task> &tasks) {
    string taskName;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, taskName);
    Task t;
    t.name = taskName;
    t.done = false;
    tasks.push_back(t);
    cout << "Task added.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name;
        if (tasks[i].done) cout << " (Completed)";
        cout << "\n";
    }
}

void markCompleted(vector<Task> &tasks) {
    int num;
    cout << "Enter task number to mark completed: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].done = true;
        cout << "Marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(vector<Task> &tasks) {
    int num;
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + num - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addTask(tasks);
        else if (choice == 2) viewTasks(tasks);
        else if (choice == 3) markCompleted(tasks);
        else if (choice == 4) removeTask(tasks);
        else if (choice == 5) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
