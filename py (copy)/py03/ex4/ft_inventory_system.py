#!/usr/bin/env python3
import sys


def get_min(inv: dict) -> int:
    smallest = None
    for value in inv.values():
        if smallest is None or value < smallest:
            smallest = value
    return smallest


def get_max(inv: dict) -> int:
    biggest = None
    for value in inv.values():
        if biggest is None or value > biggest:
            biggest = value
    return biggest


def inv_item_analysis(inv: dict) -> int:
    item_qty = 0
    for qty in inv.values():
        item_qty += qty
    print("=== Inventory System Analysis ===")
    print("Total items in inventory:", item_qty)
    print("Unique item types:", len(inv))
    return item_qty


def get_inv_content(inv: dict, inv_total: int) -> None:
    list = {}
    temp = inv.copy()
    while temp:
        k_max = None
        v_max = None
        for key, val in temp.items():
            if v_max is None or val > v_max:
                k_max = key
                v_max = val
        list[k_max] = v_max
        del temp[k_max]
    print("\n=== Current inventory ===")
    for i in list:
        item_qty = inv.get(i)
        inv_usage = (item_qty/inv_total) * 100
        print(f"{i}: {item_qty} units ({inv_usage:.1f}%)")


def get_inv_statistics(inv: dict) -> None:
    most = None
    least = None
    smol = get_min(inv)
    big = get_max(inv)
    for item, qty in inv.items():
        if most is None or least is None:
            most = least = item
            smol = big = qty
        elif qty > big:
            most = item
            big = qty
        elif qty < smol:
            least = item
            smol = qty
    print("\n=== Inventory Statistics ===")
    print(f"Most abundant: {most} ({big} units)")
    print(f"Least abundant: {least} ({smol} unit)")


def get_item_category(inv: dict) -> None:
    if len(inv) == 1:
        mod = scr = {item for item, _ in inv.items()}
    else:
        big = get_max(inv)
        moderate = {item for item, qty in inv.items() if qty == big}
        scarce = {item for item, qty in inv.items() if qty != big}
        mod = {}
        scr = {}
        for item in moderate:
            mod[item] = inv.get(item)
        for item in scarce:
            scr[item] = inv.get(item)
    print("\n=== Item Categories ===")
    print(f"Moderate: {mod}")
    print(f"Scarce: {scr}")


def mgmt_suggestion(inv: dict) -> None:
    qty = None
    for unit in inv.values():
        if qty is None or unit < qty:
            qty = unit
    to_restock = [item for item, units in inv.items() if units == qty]
    print("\n=== Management Suggestions ===")
    print("Restock needed:", to_restock)


def get_dict_properties(inv):
    key = [key for key in inv.keys()]
    val = [val for val in inv.values()]
    print("\n=== Dictionary Properties Demo ===")
    print("Dictionary keys:", key)
    print("Dictionary values:", val)


def inv_item_lookup(inv: dict, item_key: str) -> None:
    in_inv = True
    if inv.get(item_key) is None:
        in_inv = False
    print(f"Sample lookup - '{item_key}' in inventory:", in_inv)


def populate_dict(inv: dict) -> None:
    if len(sys.argv) == 1:
        return None
    try:
        for i in range(1, len(sys.argv)):
            args = sys.argv[i]
            j = 0
            while j < len(args) and args[j] != ':':
                j += 1

            key = args[:j]
            value = args[j + 1:]
            inv.update({key: int(value)})
            i += 1
        return True
    except Exception:
        print("Invalid argument:", args)
        return False


if __name__ == "__main__":
    inv = dict()
    if (populate_dict(inv)):
        total = inv_item_analysis(inv)
        get_inv_content(inv, total)
        get_inv_statistics(inv)
        get_item_category(inv)
        mgmt_suggestion(inv)
        get_dict_properties(inv)
        inv_item_lookup(inv, "sword")
