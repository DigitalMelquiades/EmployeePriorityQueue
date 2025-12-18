#include <iostream>
#include "PriorityQueue.h"
#include "Employee.h"
// not using namespace std, I'm built different

int main() {
    PriorityQueue macondoEmployees(10);

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
    std::cout << "\nExtracting max salary employee:\n";
    const Employee* employee2 = macondoEmployees.deque();
    employee2->print();
    std::cout<<"After deletion: \n";
    macondoEmployees.print();

    while (!macondoEmployees.isEmpty()) macondoEmployees.deque();
    return 0;
}
// GitHub repo: https://github.com/DigitalMelquiades/EmployeePriorityQueue