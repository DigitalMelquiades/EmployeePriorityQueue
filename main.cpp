#include <iostream>
// not using namespace std, I'm built different
class Employee {
    std::string name, id, empClass;
    int salary, experience;
public:
    Employee(const std::string& name, const std::string& id, const std::string& empClass, const int& salary, const int& experience) : name(name), id(id), empClass(empClass), salary(salary), experience(experience) {}
    virtual ~Employee() = 0;
    virtual void display() = 0;
    virtual void calculateSalary() {
    }
    double getSalary() const { return salary; }
};
class Tester : public Employee {
public:
    Tester(const std::string& name, const std::string& id, const int& salary, const int& experience) : Employee(name,id,"TST",salary,experience) {}
    ~Tester() override = default;
};
class Developer : public Employee {
    std::string qualification;
public:
    Developer(const std::string& name, const std::string& id, const std::string& empClass, const int& salary, const int& experience, const std::string& qualification) : Employee(name,id,empClass,salary,experience),  qualification(qualification) {}
    ~Developer() override = default;
};
class Frontend : public Developer {
    std::string technology;
public:
    Frontend(const std::string& name, const std::string& id, const int& salary, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name,id,"FD",salary,experience, qualification), technology(technology) {}
    ~Frontend() override = default;
};
class Backend : public Developer {
    std::string technology;
public:
    Backend(const std::string& name, const std::string& id, const int& salary, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name,id,"BD",salary,experience, qualification), technology(technology) {}
    ~Backend() override = default;
};
class CIO : public Employee {
public:
    CIO(const std::string& name, const std::string& id, const int& salary, const int& experience) : Employee(name,id,"CIO",salary,experience) {}
    ~CIO() override = default;
};
class Engineer : public Employee {
    std::string qualification;
public:
    Engineer(const std::string& name, const std::string& id, const std::string& empClass, const int& salary, const int& experience, const std::string& qualification) : Employee(name,id,empClass,salary,experience),  qualification(qualification) {}
    ~Engineer() override = default;
};
class DevOps : public Engineer {
public:
    DevOps(const std::string& name, const std::string& id, const int& salary, const int& experience, const std::string& qualification) : Engineer(name,id,"DE",salary,experience, qualification) {}
    ~DevOps() override = default;
};
class Database : public Engineer {
public:
    Database(const std::string& name, const std::string& id, const int& salary, const int& experience, const std::string& qualification) : Engineer(name,id,"DB",salary,experience, qualification) {}
    ~Database() override = default;
};
class ProjectManager : public Employee {
public:
    ProjectManager(const std::string& name, const std::string& id, const int& salary, const int& experience) : Employee(name,id,"PM",salary,experience) {}
    ~ProjectManager() override = default;
};
class PriorityQueue {

};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}