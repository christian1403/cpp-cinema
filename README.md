# Cinema Management System

A comprehensive C++ console application for managing cinema operations including films, studios, schedules, and member authentication.

## 🎬 Overview

This Cinema Management System is designed to handle the core operations of a movie theater, providing functionality for managing films, studios, schedules, and member authentication. The system follows a modular architecture with clear separation between data models, views, and business logic.

## 🏗️ Architecture

The project follows a **Model-View-Controller (MVC)** pattern with the following structure:

```
cinema/
├── main.cpp                    # Application entry point
├── Database/                   # Data structures and storage
│   ├── FilmDatabase.h         # Film data structure
│   ├── JadwalDatabase.h       # Schedule data structure  
│   ├── MemberDatabase.h       # Member data structure
│   └── StudioDatabase.h       # Studio data structure
├── Model/                      # Business logic layer
│   ├── FilmModel.h            # Film operations
│   ├── JadwalModel.h          # Schedule operations
│   ├── MemberModel.h          # Member operations
│   └── StudioModel.h          # Studio operations
└── View/                       # Presentation layer
    ├── FilmView.h             # Film user interface
    ├── JadwalView.h           # Schedule user interface
    ├── MemberView.h           # Member user interface
    └── StudioView.h           # Studio user interface
```

## 🚀 Features

### 🎭 Film Management
- Add new films with title, genre, and duration
- View all registered films in a formatted table
- Search films by title
- Display film details with proper formatting

### 🏢 Studio Management
- Create and manage cinema studios
- Set studio capacity (number of seats)
- View all studios with their specifications
- Search studios by name

### 📅 Schedule Management
- Create movie schedules linking films to studios
- Set show times, dates, and ticket prices
- View all schedules in a comprehensive table
- Search schedules by unique code
- Pointer-based linking between schedules, films, and studios

### 👥 Member Management
- Member registration with complete profile information
- Secure login authentication system
- Password management and updates
- Member profile viewing and searching
- Phone number-based member identification

## 🛠️ Technical Specifications

### Requirements
- **Compiler**: GCC 11+ with C++11 support
- **Operating System**: Linux (tested), Windows (compatible), macOS (compatible)
- **Memory**: Minimal requirements (arrays-based storage)

### Data Structures
```cpp
// Core entities
struct Film {
    string judul;        // Film title
    string genre;        // Film genre
    int durasi;          // Duration in minutes
};

struct Studio {
    string nama;         // Studio name
    int jumlahKursi;     // Seat capacity
};

struct Member {
    string nama;         // Member name
    string telp;         // Phone number (unique identifier)
    string email;        // Email address
    string password;     // Account password
};

struct Jadwal {
    string kode;         // Unique schedule code
    string jam;          // Show time (HH:MM)
    string tanggal;      // Show date (DD-MM-YYYY)
    Studio *studio;      // Pointer to studio
    Film *film;          // Pointer to film
    int hargaTiket;      // Ticket price
};
```

## 🔧 Installation & Setup

### 1. Clone the Repository
```bash
git clone https://github.com/christian1403/cpp-cinema.git
cd cpp-cinema
```

### 2. Compile the Project
```bash
# Using GCC
g++-11 -fdiagnostics-color=always -g main.cpp -o cinema

# Or using the provided VS Code task
# Press Ctrl+Shift+P -> "Tasks: Run Task" -> "C/C++: g++-11 build active file"
```

### 3. Run the Application
```bash
./cinema
```

## 🎮 Usage Guide

### Authentication
1. **Login**: Use existing member credentials
   - Default accounts available:
     - Phone: `085784089313`, Password: `password123` (Christian)
     - Phone: `085334815766`, Password: `password456` (Chandra)

### Main Menu Navigation
After successful login, access these modules:

#### 📱 Film Management
- **Add Film**: Register new movies with details
- **View Films**: Display all films in formatted table
- **Search Film**: Find specific films by title

#### 🏪 Studio Management  
- **Add Studio**: Create new cinema halls
- **View Studios**: List all available studios
- **Search Studio**: Find studios by name

#### 📋 Schedule Management
- **Add Schedule**: Create new show schedules
- **View Schedules**: Display all scheduled shows
- **Search Schedule**: Find schedules by code

## 💡 Key Features

### 🔗 Pointer-Based Architecture
The system uses efficient pointer-based linking between schedules, films, and studios, providing:
- Memory-efficient data relationships
- Fast data access and manipulation
- Scalable architecture for future enhancements

### 📊 Professional Table Formatting
All data is displayed in well-formatted tables using:
- Fixed-width columns with `setw()`
- Left-aligned text formatting
- Professional borders and separators
- Consistent spacing and readability

### 🔐 Secure Authentication
- Phone number-based unique identification
- Password protection for member accounts
- Session-based access control
- Secure login validation

## 🔮 Future Enhancements

### Planned Features
- [ ] **Ticket Booking System**: Complete reservation functionality
- [ ] **Payment Processing**: Integrated payment gateway
- [ ] **Database Integration**: MySQL/PostgreSQL support
- [ ] **Web Interface**: REST API development
- [ ] **Reporting System**: Analytics and insights
- [ ] **Multi-language Support**: Internationalization
- [ ] **Mobile App**: Cross-platform mobile application

### Technical Improvements
- [ ] **Dynamic Memory Management**: Replace arrays with dynamic structures
- [ ] **Error Handling**: Comprehensive exception management
- [ ] **Unit Testing**: Automated testing framework
- [ ] **Configuration Management**: External config files
- [ ] **Logging System**: Application activity tracking

## 🤝 Contributing

We welcome contributions! Please follow these steps:

1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. **Open** a Pull Request

### Coding Standards
- Follow existing code style and naming conventions
- Include comprehensive comments for new functions
- Maintain the MVC architecture pattern
- Test all new features thoroughly

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Authors

- **Christian** - *Lead Developer* - [christian1403](https://github.com/christian1403)

## 🙏 Acknowledgments

- Semester 2 C++ Programming Course
- Object-Oriented Programming Principles
- Modern C++ Best Practices
- Cinema Industry Standards

## 📞 Support

For support, questions, or suggestions:
- **Email**: christian@user.com
- **GitHub Issues**: [Create an issue](https://github.com/christian1403/cpp-cinema/issues)
- **Documentation**: Check this README and inline code comments

---

*Built with ❤️ using C++ for educational and practical cinema management purposes.*