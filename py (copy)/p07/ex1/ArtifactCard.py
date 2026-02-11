from ex0.Card import Card

class ArtifactCard(Card):
    def __init__(self, name: str, cost: int, rarity: str, durability: int, effect: str):
        super().__init__(name, cost, rarity)
        self.type = "Artifact"
        self.durability = durability
        self.effect = effect
        self.in_play = False

    def play(self, game_state: dict) -> dict:
        result = {
            "card_played": self.name,
            "mana_used": self.cost,
            "effect": self.effect
        }
        return result

    def activate_ability(self) -> dict:
        if self.durability > 0:
            state = {
                "turns_left": self.durability,
                "effect": self.effect
            }
            self.durability -= 1
            self.in_play = True
            return state
        else:
            print(f"{self.name} has been destroyed")
            self.in_lpay = False
            return None