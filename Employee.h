//
// Created by DigitalMelquiades on 12/18/25.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H
#include <iostream>

class Employee {
    std::string name, id, empClass; // I could have used 'protected' to access variables easier
    int salary, experience; // But I prefer have those as private members and use getter-setters
public:
    Employee(const std::string& name, const std::string& id, const std::string& empClass, const int& experience);
    virtual ~Employee();
    virtual void calculateSalary();
    void setSalary(const int& salary);
    int getSalary() const;
    std::string getName() const;
    std::string getID() const;
    int getExperience() const;
    virtual void print() const;
};
class Tester : public Employee {
    std::string qualification;
public:
    Tester(const std::string& name, const std::string& id, const int& experience, const std::string& qualification);
    ~Tester() override;
    void calculateSalary() override;
    void print() const override;
};
class Developer : public Employee {
    std::string qualification;
    std::string technology;
public:
    Developer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification, const std::string& technology);
    virtual ~Developer();
    virtual std::string getQualification() const;
    virtual std::string getTechnology() const;
};
class Frontend : public Developer {
public:
    Frontend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology);
    ~Frontend() override;
    void calculateSalary() override;
    void print() const override;
};
class Backend : public Developer {
    std::string technology;
public:
    Backend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology);
    ~Backend() override;
    void calculateSalary() override;
    void print() const override;
};
class CIO : public Employee {
public:
    CIO(const std::string& name, const std::string& id, const int& experience);
    ~CIO() override;
    void calculateSalary() override;
    void print() const override;
};
class Engineer : public Employee {
    std::string qualification;
public:
    Engineer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification);
    virtual ~Engineer();
    virtual std::string getQualification() const;
};
class DevOps : public Engineer {
public:
    DevOps(const std::string& name, const std::string& id, const int& experience, const std::string& qualification);
    ~DevOps() override;
    void calculateSalary() override;
    void print() const override;
};
class Database : public Engineer {
public:
    Database(const std::string& name, const std::string& id, const int& experience, const std::string& qualification);
    ~Database() override;
    void calculateSalary() override;
    void print() const override;
};
class ProjectManager : public Employee {
public:
    ProjectManager(const std::string& name, const std::string& id, const int& experience);
    ~ProjectManager() override;
    void calculateSalary() override;
    void print() const override;
};

#endif //EMPLOYEE_EMPLOYEE_H