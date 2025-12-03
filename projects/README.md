# Note App

A simple C terminal application to manage notes stored in a binary file (notes.db). Notes have an auto-incremented integer id, a fixed-size title (64 chars), and a fixed-size body (1024 chars).

Key components:
- Data model: struct Note { id, title[64], body[1024] } stored with fwrite/fread in NOTES_FILE (notes.db).
- next_id: scans the file to find the max id and returns max+1.
- list_notes: iterates through the file and prints [id] title for each note.
- read_line: safe line input using fgets, strips trailing newline.
- create_note: prompts for title and multiline body (terminated by an empty line), assigns a new id, appends to the file.
- load_note: searches the file for a given id and optionally returns the note and its file position.
- view_note: asks for an id and prints the note title/body.
- edit_note: updates title and optionally replaces body; writes back using fseek to the note position.
- delete_note: copies all notes except the selected id into a temporary file, replaces the original file, then reopens notes.db.

Program flow:
- main opens notes.db (creating it if missing) and shows a menu loop with options: List, Create, View, Edit, Delete, Exit.
- Input uses scanf for menu numbers and read_line/fgets for strings, with buffer limits to avoid overflow.

Build & run (inside projects/note_app):
- A Makefile is provided; typically `make` builds the `note_app` binary.
- Run `./note_app` to start the interactive menu.

Notes on storage and limits:
- Fixed-size fields mean titles and bodies are truncated if longer than their buffers.
- Body entry ends when you submit an empty line; large bodies are prevented with a size check.
- File format is a simple sequence of Note structs; there is no indexing beyond linear scans.
