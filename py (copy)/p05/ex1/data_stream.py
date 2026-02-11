#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any, List, Optional, Dict, Union


def isfloat(line: str) -> bool:
    dots = 0
    for i, a in enumerate(line):
        if a == ".":
            if i == 0 or dots == 1:
                return False
            dots += 1
        elif not a.isdigit():
            return False
    return True


class DataStream(ABC):
    def __init__(self, stream_id: str):
        print("")
        self.id = stream_id
        self.processed = []

    @abstractmethod
    def process_batch(self, data_batch: List[Any]) -> str:
        pass

    def filter_data(self, data_batch: List[str], creteria: Optional[str]):
        return [ev for ev in data_batch if creteria in ev]

    def get_stats(self) -> Dict[str, Union[str, int, float]]:
        if self.isinstance(SensorStream):
            unit = "readings"
        elif self.isinstance(TransactionStream):
            unit = "operations"
        elif self.isinstance(EventStream):
            unit = "events"
        return {
            "id": self.id,
            "processed": len(self.processed),
            "unit": unit
        }


class SensorStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        print("Initializing Sensor Stream...")
        print(f"Stream ID: {stream_id}, Type: Environmental Data")

    def process_batch(self, data_batch: List[str]) -> None:
        for part in data_batch:
            if (
                (part.startswith("temp:")
                    or part.startswith("pressure:")
                    or part.startwith("humidity:"))
                and isfloat(part.split(":")[1])
            ):
                self.processed.append(part)
            else:
                print(part, "Cancelled: wrong format.")
        print("Processing sensor batch:", data_batch)

    def get_stats(self) -> None:
        t = [float(ev.split(":")[1]) for ev in self.processed if "temp" in ev]
        print(f"Sensor analysis: {len(self.processed)} reading processed, " +
              f"avg temp: {sum(t) / len(t)}°C")


class TransactionStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        print("Initializing Transaction Stream...")
        print(f"Stream ID: {stream_id}, Type: Financial Data")

    def process_batch(self, data_batch: List[str]) -> None:
        for part in data_batch:
            if (
                    (part.startswith("sell:") or part.startswith("buy:"))
                    and part.split(":")[1].isdigit()
            ):
                self.processed.append(part)
            else:
                print(part, "Cancelled: wrong format, " +
                            "should be 'sell:[NUMBER]' or 'buy:[NUMBER]'")
        print("Processing transaction batch:", data_batch)

    def get_stats(self) -> None:
        d = sum([int(c.split(":")[1]) for c in self.processed if "sell" in c])
        d -= sum([int(c.split(":")[1]) for c in self.processed if "buy" in c])
        print(f"Transaction Analysis: {len(self.processed)} operations, " +
              f"net flow {d} units")


class EventStream(DataStream):
    def __init__(self, stream_id: str):
        super().__init__(stream_id)
        print("Initializing Event Stream...")
        print(f"Stream ID: {stream_id}, Type: System Events")

    def process_batch(self, data_batch: List[str]) -> None:
        for part in data_batch:
            if not (
                part.startswith("login")
                or part.startswith("logout")
            ):
                part = "ERROR: " + part
            self.processed.append(part)
        print("Processing event batch:", data_batch)

    def get_stats(self) -> None:
        err = sum([1 for ev in self.processed if ev.startswith("ERROR:")])
        count = len(self.processed) - err
        print(f"Event analysis: {count} events, {err} errors detected")


class StreamManager:
    def process(prs: List[DataStream]):
        print("Batch 1 Results:")
        for pr in prs:
            pr.get_stats()


print("=== CODE NEXUS - POLYMORPHIC STREAM SYSTEM ===")
sensor = SensorStream("SENSOR_001")
sensor.process_batch(["temp:22", "temp:10", "temp:13.41a"])
sensor.get_stats()

transaction = TransactionStream("TRANS_001")
transaction.process_batch(["buy:200", "sell:1120", "sell:99", "sf:21"])
transaction.get_stats()

event = EventStream("EVENT_001")
event.process_batch(["sdf", "login p1", "login p2", "logout p1", "error"])
event.get_stats()

print("\n=== Polymorphic Stream Processing ===")
print("Processing mixed stream types through unified interface...\n")
StreamManager.process([sensor, transaction, event])
print("\nStream filtering active: logins")
print("Filtered:", event.filter_data(event.processed, "login"), "logins")
print("\nAll streams processed successfully. Nexus throughput optimal.")
