//
// Created by DigitalMelquiades on 12/18/25.
//
#include "Employee.h"

Employee::Employee(const std::string& name, const std::string& id, const std::string& empClass, const int& experience) : name(name), id(id), empClass(empClass), experience(experience) {}
void Employee::calculateSalary() {}
void Employee::print() const {}
void Employee::setSalary(const int& salary) { this->salary = salary; }
int Employee::getSalary() const { return salary; }
std::string Employee::getName() const { return name; }
std::string Employee::getID() const { return id; }
int Employee::getExperience() const { return experience; }
Tester::Tester(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Employee(name,id,"TST",experience), qualification(qualification) { calculateSalary(); }
void Tester::calculateSalary() {
        int salary = 2000;
        if (qualification == "Senior") salary *= 2;
        else if (qualification == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        setSalary(salary);
}
void Tester::print() const {
        std::cout<<"=======Tester=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<qualification<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
Developer::Developer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification, const std::string& technology) : Employee(name,id,empClass,experience),  qualification(qualification) {};
std::string Developer::getQualification() const { return qualification; }
std::string Developer::getTechnology() const { return technology; }
Frontend::Frontend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name, id, "FD", experience, qualification, technology) { calculateSalary(); }
void Frontend::calculateSalary() {
    int salary = 2500;
    if (getQualification() == "Senior") salary *= 2;
    else if (getQualification() == "Middle") salary *= 1.5;
    salary += getExperience() * 50;
    if (getTechnology() == "Vue") salary += 100;
    else if (getTechnology() == "Angular") salary += 200;
    else if (getTechnology() == "React") salary += 300;
    setSalary(salary);
}
void Frontend::print() const {
    std::cout<<"=======Frontend=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Qualification: "<<getQualification()<<std::endl;
    std::cout<<"Technology: "<<getTechnology()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
Backend::Backend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name,id,"BD",experience, qualification, technology) { calculateSalary(); }
void Backend::calculateSalary() {
    int salary = 3000;
    if (getQualification() == "Senior") salary *= 2;
    else if (getQualification() == "Middle") salary *= 1.5;
    salary += getExperience() * 50;
    if (getTechnology() == ".Net") salary += 100;
    else if (getTechnology() == "Spring") salary += 200;
    else if (getTechnology() == "Django") salary += 300;
    setSalary(salary);
}
void Backend::print() const  {
    std::cout<<"=======Backend=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Qualification: "<<getQualification()<<std::endl;
    std::cout<<"Technology: "<<getTechnology()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
CIO::CIO(const std::string& name, const std::string& id, const int& experience) : Employee(name,id,"CIO",experience) { calculateSalary(); }
void CIO::calculateSalary() { setSalary(5000 + getExperience() * 50); }
void CIO::print() const {
    std::cout<<"=======CIO=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
Engineer::Engineer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification) : Employee(name,id,empClass,experience),  qualification(qualification) {}
std::string Engineer::getQualification() const { return qualification; }
DevOps::DevOps(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Engineer(name,id,"DE",experience, qualification) { calculateSalary(); }
void DevOps::calculateSalary() {
    int salary = 2800;
    if (getQualification() == "Senior") salary *= 2;
    else if (getQualification() == "Middle") salary *= 1.5;
    salary += getExperience() * 50;
    setSalary(salary);
}
void DevOps::print() const {
    std::cout<<"=======DevOps=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Qualification: "<<getQualification()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
Database::Database(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Engineer(name,id,"DB",experience, qualification) { calculateSalary(); }
void Database::calculateSalary() {
    int salary = 2900;
    if (getQualification() == "Senior") salary *= 2;
    else if (getQualification() == "Middle") salary *= 1.5;
    salary += getExperience() * 50;
    setSalary(salary);
}
void Database::print() const {
    std::cout<<"=======Database=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Qualification: "<<getQualification()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
ProjectManager::ProjectManager(const std::string& name, const std::string& id, const int& experience) : Employee(name,id,"PM",experience) { calculateSalary(); }
void ProjectManager::calculateSalary() { setSalary(3000 + getExperience() * 50); }
void ProjectManager::print() const {
    std::cout<<"=======ProjectManager=======\n";
    std::cout<<"Name: "<<getName()<<std::endl;
    std::cout<<"ID: "<<getID()<<std::endl;
    std::cout<<"Experience: "<<getExperience()<<std::endl;
    std::cout<<"Salary: "<<getSalary()<<std::endl;
    std::cout<<"====================\n";
}
Employee::~Employee() = default;
Tester::~Tester() = default;
Developer::~Developer() = default;
Engineer::~Engineer() = default;
Frontend::~Frontend() = default;
Backend::~Backend() = default;
CIO::~CIO() = default;
DevOps::~DevOps() = default;
Database::~Database() = default;
ProjectManager::~ProjectManager() = default;