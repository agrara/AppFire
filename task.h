#pragma once

#include <iostream>
#include <string>
#include <vector>

class Task
{
public:
    // Constructors
    Task(std::string newTitle, std::string newDesc) : title(newTitle), desc(newDesc) {}

    // Title
    std::string getTitle()
    {
        return this->title;
    }
    void setTitle(std::string newTitle)
    {
        this->title = newTitle;
    }

    // Description
    std::string getDesc()
    {
        return this->desc;
    }
    void setDesc(std::string newDesc)
    {
        this->desc = newDesc;
    }

private:
    std::string title;
    std::string desc;
};

/*
Adds a new task
@params title, description
@return pointer to the newly created task
*/
Task *addTask(std::string, std::string);

/*
Deletes a given task
@params pointer to the task to be deleted
@return 0 on success, -1 on failure
*/
int deleteTask(Task *);

/*
Edits the title and the description of a given task
@params pointer to the task to be edited, the new title, the new description
@return 0 on success, -1 on failure
*/
int editTask(Task *, std::string, std::string);

/*
Shows a list of all the tasks
@params vector containing all the tasks
@return 0 on success, -1 if there are no tasks
*/
int listAllTasks(std::vector<Task *>);