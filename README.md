
# NutritionPlanner

NutritionPlanner is a web application that helps users plan and manage their nutrition intake effectively. It provides an intuitive interface for creating meal plans, tracking nutritional data, and making informed dietary decisions.

## Project Overview

NutritionPlanner Frontend is built using React, leveraging Bootstrap for responsive design and Axios for handling API requests. This project is structured to allow easy expansion and customization.

NutritionPlanner Backend application built using the Qt framework, designed to handle server-side processing and data management in a multi-threaded manner.

## Software Requirements

### Frontend
- **Node.js** (v18.19.1 or higher)
- **npm** (v9.2.0 or higher)

### Backend
- **Qt Framework** (version 6.x or higher)
- **C++ Compiler** (compatible with Qt, e.g., GCC, MSVC)
- **CMake** (for building the project)


## Backend Architecture

![Screenshot of the Application](Images/arch.png)


## Demo

### Frontend:

![Screenshot of the Application](images/front1.png)
![Screenshot of the Application](images/front2.png)

### Backend:
![Screenshot of the Application](images/back.png)


## Installation

### Frontend

To set up the project locally, follow these steps:

1. **Clone the repository:**

   \```bash
   git clone https://github.com/your-username/NutritionPlanner.git
    \```

2. **Navigate to the project directory**
    \```bash
    cd NutritionPlanner
    \```

3. **Install the dependencies**
    \```bash
    npm install
    \```

4. **Build the source code**
    \```bash
    npm run build
    \```


5. **Start the development server**
    \```bash
    npm run start
    \```

This will launch the app in your default browser. You can access it at http://localhost:3000

### Backend

1. Ensure that Qt is installed on your system. You can download it from Qt's official website.

2. Import the project in Qt Creator using the CMakeLists.txt file.

3. Build and Run the project.

## Logging

Logs are written to 2 files 

1. requests_log.txt for new Patient requests.
2. feedbacks_log.txt for new Feedbacks.






