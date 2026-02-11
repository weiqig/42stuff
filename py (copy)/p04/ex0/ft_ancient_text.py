#!/usr/bin/env python3
def recover_text_fragment(filename: str) -> None:
    print("=== CYBER ARCHIVES - DATA RECOVERY SYSTEM ===")
    print("\nAccessing Storage Vault:", filename)
    f = None
    try:
        f = open(filename, "r")
        print("Connection established...")
        print("\nRECOVERED DATA:")
        print(f.read())
        f.close()
    except (FileNotFoundError, ValueError):
        print("ERROR: Storage vault not found.")
    else:
        print("\nData recovery complete. Storage unit disconnected.")


recover_text_fragment("ancient_fragment.txt")
# recover_text_fragment("the_rat_files.txt")
