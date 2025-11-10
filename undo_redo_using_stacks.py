# Undo/Redo System using Stack

undo_stack = []   # stores previous document states
redo_stack = []   # stores undone document states
document = ""     # current state of document


def make_change(new_text):
    global document
    undo_stack.append(document)   # save current state before changing
    document = new_text
    redo_stack.clear()            # clear redo stack after new change
    print("Change made.")


def undo_action():
    global document
    if not undo_stack:
        print("Nothing to undo.")
    else:
        redo_stack.append(document)
        document = undo_stack.pop()
        print("Undo done.")


def redo_action():
    global document
    if not redo_stack:
        print("Nothing to redo.")
    else:
        undo_stack.append(document)
        document = redo_stack.pop()
        print("Redo done.")


def display_document():
    print("Current document state:", document)


# --- Example usage ---
make_change("Hello")
make_change("Hello World")
make_change("Hello World!!!")

display_document()

undo_action()
display_document()

undo_action()
display_document()

redo_action()
display_document()
