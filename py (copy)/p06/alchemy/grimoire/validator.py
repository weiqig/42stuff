def validate_ingredients(ingredients: str) -> str:
    valid = ["fire", "water", "earth", "air"]
    list = ingredients.split()
    for ingredient in list:
        if (ingredient not in valid):
            return f"{ingredients} - INVALID", 0
    return f"{ingredients} - VALID", 1
