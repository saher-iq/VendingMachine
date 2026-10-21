

\# Vending Machine - C++



A console-based vending machine developed in C++ using CMake and the State Design Pattern.



\## Project Features



\- Displays available products and their prices.

\- Allows users to select a product.

\- Checks whether the inserted money is sufficient.

\- Rejects invalid product choices and negative amounts.

\- Calculates and displays the change after a successful purchase.

\- Uses the State Design Pattern to manage purchase processing.

\- Includes automated unit tests using GoogleTest.



\## Products



| Product | Price |

|---|---:|

| Water | 500 IQD |

| Juice | 1000 IQD |

| Soda | 750 IQD |



\## Technologies



\- C++17

\- CMake

\- GoogleTest

\- Git and GitHub



\## Project Structure



```text

VendingMachine/

├── CMakeLists.txt

├── src/

│   ├── main.cpp

│   ├── Product.h

│   ├── Product.cpp

│   ├── State.h

│   ├── State.cpp

│   ├── VendingMachine.h

│   └── VendingMachine.cpp

├── tests/

│   └── VendingMachineTests.cpp

└── README.md

```



\## Build Instructions



Configure the project:



```bash

cmake -S . -B build

```



Build the project:



```bash

cmake --build build

```



\## Run the Program



On Windows with the Visual Studio Debug configuration:



```bat

build\\Debug\\VendingMachine.exe

```



\## Run Unit Tests



```bash

ctest --test-dir build -C Debug --output-on-failure

```



The project currently has 9 passing unit tests.



\## Design Pattern



The project uses the \*\*State Design Pattern\*\*. The vending machine has two states:



\- \*\*ReadyState:\*\* Validates the product selection and inserted amount.

\- \*\*DispensingState:\*\* Processes a valid purchase, displays the change, and returns the machine to the ready state.



\## Repository



https://github.com/saher-iq/VendingMachine



