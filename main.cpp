#include <iostream>
#include <vector>
#include <fstream>
// not using namespace std, I'm built different
class Employee {
    std::string name, id, empClass; // I could have used 'protected' to access variables easier
    int salary, experience; // But I prefer have those as private members and use getter-setters
public:
    Employee(const std::string& name, const std::string& id, const std::string& empClass, const int& experience) : name(name), id(id), empClass(empClass), experience(experience) {}
    virtual ~Employee() {};
    virtual void calculateSalary() = 0;
    void setSalary(const int& salary) { this->salary = salary; }
    int getSalary() const { return salary; }
    std::string getName() const { return name; }
    std::string getID() const { return id; }
    int getExperience() const { return experience; }
    virtual void print() const = 0;
};
class Tester : public Employee {
    std::string qualification;
public:
    Tester(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Employee(name,id,"TST",experience), qualification(qualification) { calculateSalary(); }
    ~Tester() override = default;
    void calculateSalary() override {
        int salary = 2000;
        if (qualification == "Senior") salary *= 2;
        else if (qualification == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        setSalary(salary);
    }
    void print() const override {
        std::cout<<"=======TESTER=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<qualification<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class Developer : public Employee {
    std::string qualification;
    std::string technology;
public:
    Developer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification, const std::string& technology) : Employee(name,id,empClass,experience),  qualification(qualification) {};
    ~Developer() override = default;
    std::string getQualification() const { return qualification; }
    std::string getTechnology() const { return technology; }
};
class Frontend : public Developer {
public:
    Frontend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name,id,"FD",experience, qualification, technology) { calculateSalary(); }
    ~Frontend() override = default;
    void calculateSalary() override {
        int salary = 2500;
        if (getQualification() == "Senior") salary *= 2;
        else if (getQualification() == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        if (getTechnology() == "Vue") salary += 100;
        else if (getTechnology() == "Angular") salary += 200;
        else if (getTechnology() == "React") salary += 300;
        setSalary(salary);
    }
    void print() const override {
        std::cout<<"=======Frontend=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<getQualification()<<std::endl;
        std::cout<<"Technology: "<<getTechnology()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class Backend : public Developer {
    std::string technology;
public:
    Backend(const std::string& name, const std::string& id, const int& experience, const std::string& qualification, const std::string& technology) : Developer(name,id,"BD",experience, qualification, technology) { calculateSalary(); }
    ~Backend() override = default;
    void calculateSalary() override {
        int salary = 3000;
        if (getQualification() == "Senior") salary *= 2;
        else if (getQualification() == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        if (getTechnology() == ".Net") salary += 100;
        else if (getTechnology() == "Spring") salary += 200;
        else if (getTechnology() == "Django") salary += 300;
        setSalary(salary);
    }
    void print() const override {
        std::cout<<"=======Backend=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<getQualification()<<std::endl;
        std::cout<<"Technology: "<<getTechnology()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class CIO : public Employee {
public:
    CIO(const std::string& name, const std::string& id, const int& experience) : Employee(name,id,"CIO",experience) { calculateSalary(); }
    ~CIO() override = default;
    void calculateSalary() override { setSalary(5000 + getExperience() * 50); }
    void print() const override {
        std::cout<<"=======CIO=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class Engineer : public Employee {
    std::string qualification;
public:
    Engineer(const std::string& name, const std::string& id, const std::string& empClass, const int& experience, const std::string& qualification) : Employee(name,id,empClass,experience),  qualification(qualification) {}
    ~Engineer() override = default;
    std::string getQualification() const { return qualification; }
};
class DevOps : public Engineer {
public:
    DevOps(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Engineer(name,id,"DE",experience, qualification) { calculateSalary(); }
    ~DevOps() override = default;
    void calculateSalary() override {
        int salary = 2800;
        if (getQualification() == "Senior") salary *= 2;
        else if (getQualification() == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        setSalary(salary);
    }
    void print() const override {
        std::cout<<"=======DevOps=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<getQualification()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class Database : public Engineer {
public:
    Database(const std::string& name, const std::string& id, const int& experience, const std::string& qualification) : Engineer(name,id,"DB",experience, qualification) { calculateSalary(); }
    ~Database() override = default;
    void calculateSalary() override {
        int salary = 2900;
        if (getQualification() == "Senior") salary *= 2;
        else if (getQualification() == "Middle") salary *= 1.5;
        salary += getExperience() * 50;
        setSalary(salary);
    }
    void print() const override {
        std::cout<<"=======Database=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Qualification: "<<getQualification()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class ProjectManager : public Employee {
public:
    ProjectManager(const std::string& name, const std::string& id, const int& experience) : Employee(name,id,"PM",experience) { calculateSalary(); }
    ~ProjectManager() override = default;
    void calculateSalary() override { setSalary(3000 + getExperience() * 50); }
    void print() const override {
        std::cout<<"=======ProjectManager=======\n";
        std::cout<<"Name: "<<getName()<<std::endl;
        std::cout<<"ID: "<<getID()<<std::endl;
        std::cout<<"Experience: "<<getExperience()<<std::endl;
        std::cout<<"Salary: "<<getSalary()<<std::endl;
        std::cout<<"====================\n";
    }
};
class PriorityQueue {
    std::vector<Employee*> heap;
    int size, capacity;
public:
    PriorityQueue() = default;
    PriorityQueue(const int& capacity) : size(0), capacity(capacity) { heap.reserve(capacity); }
    ~PriorityQueue() = default;
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == this->capacity; }
    void heapifyUp(int index) {
        while (index > 0) {
            int p = (index-1)/2;
            if (heap[index]->getSalary() > heap[p]->getSalary()) {
                std::swap(heap[index], heap[p]);
                index = p;
            } else break;
        }
    }
    void heapifyDown(int index) {
        while (true) {
            int left = (2 * index) + 1, right = (2 * index) + 2, largest = index;
            if (left < size && heap[left]->getSalary() > heap[largest]->getSalary()) largest = left;
            if (right < size && heap[right]->getSalary() > heap[largest]->getSalary()) largest = right;
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else break;
        }
    }
    void enque(Employee* employee) {
        if (size == capacity) throw std::out_of_range("Queue full");
        heap.push_back(employee);
        heapifyUp(size);
        size++;
    }
    Employee* deque() {
        if (heap.empty()) throw std::out_of_range("Queue is empty!");
        Employee* max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        size--;
        if (size>0) heapifyDown(0);
        return max;
    }
    void print() const { for (const auto& employee:heap) if (employee) employee->print(); }
};

int main() {
    PriorityQueue macondoEmployees(27);

    auto* melquiades = new CIO("Melquiades", "1", 120);
    auto* jose = new ProjectManager("Jose Arcadio Buendia", "2", 90);
    auto* ursula = new Tester("Ursula Iguaran", "3", 36, "Junior");
    auto* rebeca = new Tester("Rebeca Buendia", "4", 60, "Senior");
    auto* coronel = new Frontend("Coronel Aureliano Buendia", "5", 48, "Senior", "React");
    auto* arcadio = new Frontend("Arcadio Buendia", "6", 48, "Middle", "Angular");
    auto* remedio = new Backend("Remedios Moscote", "7", 72, "Junior", "Django");
    auto* babilonia = new Backend("Aureliano Babilonia", "8", 72, "Senior", ".Net");
    auto* artemio = new Database("Artemio Cruz", "9", 30, "Junior"); // Invited guest
    auto* andria = new DevOps("Andria Lamazi Bichia", "10", 30, "Junior");

    macondoEmployees.enque(melquiades);
    macondoEmployees.enque(jose);
    macondoEmployees.enque(ursula);
    macondoEmployees.enque(rebeca);
    macondoEmployees.enque(coronel);
    macondoEmployees.enque(arcadio);
    macondoEmployees.enque(remedio);
    macondoEmployees.enque(babilonia);
    macondoEmployees.enque(artemio);
    macondoEmployees.enque(andria);

    macondoEmployees.print();
    std::cout << "\nExtracting max salary employee:\n";
    const Employee* employee = macondoEmployees.deque();
    employee->print();
    std::cout<<"After deletion: \n";
    macondoEmployees.print();

    while (!macondoEmployees.isEmpty()) macondoEmployees.deque();

    return 0;
}
// GitHub repo: https://github.com/DigitalMelquiades/EmployeePriorityQueue