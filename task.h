#pragma once

#include <iostream>
#include <string>
#include <vector>

class Task
{
public:
    // Constructors
    Task(std::string newTitle, std::string newDesc) : title(newTitle), desc(newDesc) {}

    // Destructor
    virtual ~Task()
    {
        std::cout << "Congaratulations for finishing " << this->getTitle() << "!" << std::endl;
    }

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

Task *addTask(std::string, std::string);
int deleteTask(Task *);
int editTask(Task *, std::string, std::string);
int listAllTasks(std::vector<Task *>);