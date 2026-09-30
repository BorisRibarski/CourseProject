# Course Project — Library Management Console Application

## Overview

This project is a small console-based Library Management application written in modern C++ (C++23). It was developed as a course project for a discipline at the Technical University — Sofia. The program provides a simple text-based user interface to manage a collection of items (books, magazines, audio CDs, etc.), persist the collection to a file, and load it back.

The repository layout is as follows (relevant paths):
- `src/` — application source code
- `src/app/` — `application` orchestrator
- `src/cli/` — console UI and screen builder
- `src/fio/` — file input/output handlers (reader, writer)
- `src/lib/` — core domain classes (`library`, `data_carrier`, types)
- `data/` — default import/export files (`data/import`, `data/export`)
- `target/` — build target (`target/program`)
- `makefile` — build rules

The program is invoked from `main` which parses optional command-line arguments for input/output file paths and then constructs `app::application` with those filenames. The `application` object runs an interactive menu loop that accepts user commands and manipulates an in-memory `lib::library` instance.

## Design and Architecture

High-level components and responsibilities:
- `app::application` — central orchestrator that composes the UI (`cli::console`), persistence (`fio::reader`, `fio::writer`), and domain logic (`lib::library`). It implements menu flows and user command handlers.
- `cli::console` and `cli::screen` — provide the textual user interface and rendering utilities. `screen_builder` helps assemble consistent bordered screens.
- `lib::library` — in-memory collection of `data_carrier` objects. Offers add/remove/change operations, filters for available/non-available items, and load/save helpers converting between `data_carrier` and text lines.
- `lib::data_carrier` — domain entity representing a single item in the library. Encapsulates fields: type, author, title, release year, availability. Provides serialize/deserialize helpers.
- `fio::reader` / `fio::writer` — thin wrappers around file streams for reading/writing lines.

The overall control flow is sequential and synchronous: `main` -> build `application` -> `application.run()` -> menus and command handlers -> `reader`/`writer` for persistence.

## Key Files and Components

- `src/main.cc`
  - Parses CLI arguments (`--input-file`, `--output-file`, `--file`, `--verbose`). Falls back to `data/import` and `data/export` when paths are not provided.
  - Creates `app::application` and calls `run()`.

- `src/app/application.hh` and `src/app/application.cc`
  - Holds members: `lib::library lib`, `cli::console terminal`, `fio::reader reader`, `fio::writer writer`.
  - Implements top-level menus: home, entity management, library management, and lists. Handlers include `add_new()`, `invert()` (toggle availability), `remove()`, `load()`, `save()`, and listing helpers.

- `src/cli/console.hh` and `src/cli/console.cc`
  - Implements user prompts and menu rendering. Methods like `show_home()`, `show_entity_mgmt()`, `show_list()`, `question()` and `get_answer()` encapsulate I/O.

- `src/cli/screen.hh` and `src/cli/screen.cc`
  - `screen_builder` composes lines with a fixed width (80) and decorative borders. `screen` prints the assembled matrix to the terminal and clears the terminal between screens.

- `src/lib/data_carrier.hh` and `src/lib/data_carrier.cc`
  - `data_carrier` carries fields and provides `toString()`, `toLine()` (serialize), and `fromLine()` (parse) methods. Parsing uses `std::views::split` and `std::from_chars` for robust numeric conversion.
  - `data_carrier_type` enumerates supported media types.

- `src/lib/library.hh` and `src/lib/library.cc`
  - Manages `std::vector<data_carrier>` as `shelf`. Offers `add`, `remove`, `change` (toggle availability), `get_available`, `get_non_available`, `get_all`, `load`, and `save` methods.

- `src/fio/handler.hh`, `reader.hh`, `writer.hh` and their `.cc` implementations
  - Implement file open/read/write using `std::ifstream` / `std::ofstream` (encapsulated in `handler`). `reader::read()` returns a vector of lines; `writer::write()` writes lines to the file.

## Data Format

Saved items use a simple custom line format: `[type;author;title;year;available]`
- `type` — integer matching `data_carrier_type` enum (0 = Book, 1 = Magazine, ...)
- `author` — string (no escaping implemented)
- `title` — string (no escaping implemented)
- `year` — integer
- `available` — text `true` or `false`

Example line:

[0;J.K.Rowling;HarryPotter;1997;true]

`data_carrier::fromLine()` strips surrounding brackets and splits by `;`. Numeric fields use `std::from_chars` for parsing.

Limitations: fields are not escaped; semicolons or brackets in author/title will break parsing.

## Build and Run

Requirements: a C++23-capable compiler (tested with `g++`), `make`.

Build and run using the provided `makefile`:

```bash
make all
./target/program
```

Optional CLI flags:
- `--file` or `-f <path>` — set both input and output file to `<path>`
- `--input-file` or `-i <path>` — set input file
- `--output-file` or `-o <path>` — set output file
- `--verbose` or `-v` — prints limited debug messages

The default files are `data/import` and `data/export` relative to the repository root.

## User Guide (how to use)

1. Start the program. The home menu appears.
2. Choose `1. Entity Management` to add, remove, or toggle availability of items:
   - Add New: enter numeric type (0..5), author, title, and year. New items are added as available by default.
   - Remove: enter the index number to delete an item from the shelf.
   - Get/Return (invert): enter the index number to toggle availability.
3. Choose `2. List view` to view available, non-available, or all items. Use the `Exit` option to return.
4. Choose `3. Library Management` to load from or save to the configured files.
5. Choose `4. Exit` to quit the application.

Note: Index numbers shown in lists correspond to the internal `shelf` order (0-based in code but displayed starting from 1).

## Testing and Extensibility Notes

Testing: the project currently contains no automated tests. Recommended quick checks:
- Populate `data/import` with a few lines using the `[type;author;title;year;available]` format and run the program to verify `load()`.
- Add items via `Add New`, then `Save to file`, and inspect `data/export` for expected serialized lines.

Extensibility suggestions:
- Add robust CSV/JSON persistence for safer escaping and interoperability.
- Implement stable IDs for items instead of positional indices.
- Add validation for user input (reject invalid type codes, years out of range, empty strings).
- Add unit tests using a framework like Catch2 or Google Test and CI via GitHub Actions.
- Improve UI by supporting multi-word input for author/title (currently handled, but consider line-based input to include spaces).

## Implementation Notes and Code Quality

- Modern C++ features used: `std::span`, `std::format`, `std::views::split`, `std::from_chars`, `std::to_underlying`.
- The code is organized into small, focused translation units matching logical components.
- Error handling is basic: many operations print a message on failure and continue. Consider converting to `std::optional`/`std::expected` or exceptions for stronger error semantics.
- `reader`/`writer` open files without explicit file mode flags; consider using `std::ofstream::trunc`/`app` when appropriate.

## Security and Safety Considerations

- The parser assumes well-formed input; maliciously crafted lines could cause parsing anomalies. Always validate input before loading from untrusted sources.
- The application does not execute external commands or allocate unbounded memory based on input size, but very large files could exhaust memory.

## Appendix: Example Session

- Start program: `./target/program`
- Home: select `1` (Entity Management) → `1` (Add New)
  - Type: `0` (Book)
  - Author: `J.R.R.Tolkien`
  - Title: `TheHobbit`
  - Release year: `1937`
- Back to Home, choose `3` (Library Management) → `2` (Save to file). Check `data/export` for `[0;J.R.R.Tolkien;TheHobbit;1937;true]`.

---

This documentation provides a concise but complete explanation of what the project does, how it is structured, and how to build/run and extend it. If you want, I can:
- Generate a PDF or formatted 6–8 page document from this Markdown.
- Expand sections with code excerpts and cross-file references.
- Add unit tests or improve input validation.

Tell me which of these you'd like next.
