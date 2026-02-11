#!/usr/bin/env python3
print("=== CYBER ARCHIVES - VAULT SECURITY SYSTEM ===")
print("\nInitiating secure vault access...")
print("Vault connection established with failsafe protocols")
print("\nSECURE EXTRACTION:")
try:
    with open("classified_data.txt", "r") as classified_file:
        data = classified_file.read()
        print(data)
    print("\nSECURE PRESERVATION:")
    with open("security_protocols.txt", "r") as sec:
        data = sec.read()
        print(data)
    # with open("llama.txt", "r") as unknown:
    #     data = unknown.read()
    #     print(data)
except FileNotFoundError:
    print("Error: file not found.")
finally:
    print("Vault automatically sealed upon completion")
    print("\nAll vault operations completed with maximum security.")
