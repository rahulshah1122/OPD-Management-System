
---

# OPD Management System

A simple command-line application developed in C to manage outpatient department (OPD) operations, including patient registration, doctor information, and appointment scheduling.

## Features

- **Patient Registration**: Add and manage patient details.
- **Doctor Information**: Access information about doctors specializing in various diseases.
- **Appointment Scheduling**: Schedule appointments between patients and doctors.
- **Data Storage**: Utilizes text files to store and retrieve data.

## File Structure

- `Doctor appointment system.c`: Main source code file.
- `Doctor appointment system.exe`: Compiled executable for Windows.
- `Patient File.txt`: Stores patient information.
- `SignUp file.txt`: Contains user signup details.
- `Diseases name.txt`: List of diseases handled in the system.
- `Doctor info of - [Disease].txt`: Files containing doctor details for specific diseases (e.g., Fever, Heart Problem, Thyroid, Cancer, Diabetes).
- `Main Menu.txt`: Text representation of the main menu.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)
- Windows OS (for using the provided executable)

### Running the Application

#### Using the Executable

1. Download the repository.
2. Navigate to the directory containing `Doctor appointment system.exe`.
3. Double-click the executable to run the application.

#### Compiling from Source

1. Ensure you have a C compiler installed.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `Doctor appointment system.c`.
4. Compile the source code:

   ```bash
   gcc "Doctor appointment system.c" -o opd_management
   ```


5. Run the compiled program:

   ```bash
   ./opd_management
   ```


## Usage

- Follow the on-screen prompts to navigate through the application.
- Data entered will be stored in the corresponding `.txt` files for persistence.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

## License

This project is open-source and available under the [MIT License](LICENSE).

---

*Note: This project is a basic implementation and may not cover all aspects of a full-fledged OPD management system.*

--- 