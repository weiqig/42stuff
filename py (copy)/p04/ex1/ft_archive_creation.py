#!/usr/bin/env python3
def ft_archive_creation() -> None:
    filename = "new_discovery.txt"
    print("=== CYBER ARCHIVES - PRESERVATION SYSTEM ===")
    print("\nInitializing new storage unit: new_discovery.txt")
    try:
        f = open(filename, 'w')
        print("Storage unit created successfully...")
        print("\nInscribing preservation data...")
        f.write("[ENTRY 001] New quantum algorithm discovered\n")
        f.write("[ENTRY 002] Efficiency increased by 347%\n")
        f.write("[ENTRY 003] Archived by Data Archivist trainee")
        f.close()
        f = open(filename, 'r')
        print(f.read())
        f.close()
        print("\nData inscription complete. Storage unit sealed.")
        print(f"Archive '{filename}' ready for long-term preservation.")
    except (FileNotFoundError, PermissionError, ValueError):
        print("ERROR: Archiver crashed during archive creation.")


ft_archive_creation()
