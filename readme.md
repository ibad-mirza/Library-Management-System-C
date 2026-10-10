<div align="center">

# 📚 Library Management System

### *A lightweight, file-based book manager written in pure C*

![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Storage](https://img.shields.io/badge/storage-library.txt-orange?style=for-the-badge)
![Interface](https://img.shields.io/badge/interface-CLI-black?style=for-the-badge&logo=gnubash&logoColor=white)

*No databases. No frameworks. Just C, structs, and file handling.* ✨

</div>

---

## 📖 About

**Library Management System (LMS)** is a console application that lets you manage a book inventory straight from your terminal. Every record is saved to a plain text file (`library.txt`), so your data **persists between runs**, with nothing to install and nothing to configure.

It was built to practise core C concepts: **structures, file I/O, string handling, and modular function design**.

---

## 🚀 Features

| # | Feature | What it does |
|---|---------|--------------|
| 1 | ➕ **Add Book** | Store a new book with ID, title, author, category, price, and quantity |
| 2 | 📋 **Display All Books** | View the whole inventory in a clean list |
| 3 | 🔍 **Search Book** | Find any book instantly by its ID |
| 4 | 🗑️ **Delete Book** | Remove a book from the records |
| 5 | ✏️ **Update Book** | Edit the details of an existing book |
| 6 | 🚫 **Out-of-Stock Report** | List every book with quantity `0` |
| 7 | 💸 **Cheapest Book** | Find the lowest-priced book |
| 8 | 💎 **Most Expensive Book** | Find the highest-priced book |
| 9 | 👋 **Exit** | Close the program gracefully |

---

## 🖥️ Preview

```text
===== LIBRARY MANAGEMENT SYSTEM =====
1. Add Book
2. Display All Books
3. Search Book
4. Delete Book
5. Update Book
6. Show Out-of-Stock Books
7. Show Cheapest Book
8. Show Most Expensive Book
9. Exit
Enter your choice : 2

===== Library Books =====
ID: 101 | Title: The C Programming Language | Author: Kernighan & Ritchie | Category: Programming | Price: 45.00 | Quantity: 5
ID: 102 | Title: Clean Code | Author: Robert C. Martin | Category: Software | Price: 38.50 | Quantity: 0
=========================
```

---

## ⚙️ Getting Started

### Prerequisites
- A C compiler such as **GCC** or **Clang**

### Clone, compile, run

```bash
# 1. Clone the repository
git clone https://github.com/<your-username>/<your-repo-name>.git
cd <your-repo-name>

# 2. Compile
gcc main.c -o lms

# 3. Run
./lms          # Linux / macOS
lms.exe        # Windows
```

> 💡 Replace `main.c` with the actual name of your source file.

---

## 🗂️ How Data Is Stored

Books are saved in `library.txt` as comma-separated values, one book per line:

```text
id,title,author,category,price,quantity
101,The C Programming Language,Kernighan & Ritchie,Programming,45.00,5
```

Delete and update operations rewrite the data through a temporary file (`temp.txt`), which then replaces `library.txt`.

---

## 🧠 Concepts Demonstrated

- 🧱 **Structures** (`struct book`) to model real-world data
- 📁 **File handling** with `fopen`, `fprintf`, `fscanf`, `remove`, `rename`
- 🔤 **Formatted input** using scan sets such as `%[^\n]` for multi-word strings
- 🔁 **Menu-driven loop** with `switch`
- 🧩 **Modular design**, with one function per feature
- 🛡️ **Basic error handling** for missing or unreadable files

---

## ⚠️ Known Limitations

- Titles, authors, and categories **must not contain commas**, since commas are the field separator.
- Book IDs are **not checked for duplicates** when adding.
- Input is not fully validated (for example, typing letters where a number is expected).
- Field lengths are capped: title and author at 49 characters, category at 29.

---

## 🤝 Contributing

Suggestions and pull requests are welcome!

1. Fork the repo
2. Create your branch: `git checkout -b feature/amazing-feature`
3. Commit your changes: `git commit -m "Add amazing feature"`
4. Push and open a Pull Request

---

## 👤 Author

**Muhammad Ibad Mirza**
Computer Science student at NED University

🔗 GitHub: [@ibad-mirza](https://github.com/ibad-mirza)

---

<div align="center">

⭐ **If you found this useful, consider giving the repo a star!** ⭐

*Made with ☕ and C*

</div>