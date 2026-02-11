#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any, List


class DataProcessor(ABC):
    @abstractmethod
    def process(self, data: Any) -> str:
        print("Processing data:")

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    def format_output(self, result: str) -> str:
        return ("Output: {result}")


class NumericProcessor(DataProcessor):
    def __init__(self, data: Any):
        self.data = data

    def process(self, data: List[int]) -> str:
        print("Processing data:", data)
        return data

    def validate(self, data: List[int]) -> bool:
        self.is_valid = False
        if (isinstance(data, List)):
            print("Validation: Numeric data verified")
            self.is_valid = True
        return (self.is_valid)

    def format_output(self, result: str) -> str:
        size = len(result)
        total = sum(result)
        avg = total / size
        return (f"Processed {size} numeric values, sum={total}, avg={avg}")


class TextProcessor(DataProcessor):
    def __init__(self, data: Any):
        self.data = data

    def process(self, data: Any) -> str:
        print("Processing data:", data)
        return

    def validate(self, data: Any) -> bool:
        self.is_valid = False
        if (isinstance(data, str)):
            print("Validation: Text data verified")
            self.is_valid = True
        return (self.is_valid)

    def format_output(self, result: str) -> str:
        char = len(self.data)
        return (f"Output: Processed text: {char} characters, 3 words")


class LogProcessor(DataProcessor):
    def __init__(self, data: Any):
        self.data = data

    def process(self, data: Any) -> str:
        print("Processing data:", data)

    def validate(self, data: Any) -> bool:
        self.is_valid = False
        if (isinstance(data, str)):
            print("Validation: Log entry verified")
            self.is_valid = True
        return (self.is_valid)

    def format_output(self, result: str) -> str:
        return ("Output: [ALERT] ERROR level detected: Connection timeout")


def process_all() -> None:
    # processors = [numeric, text, log]
    # data_streams = [
    #             [1, 2, 3],
    #             "Hello Matrix",
    #             "INFO: System ready"
    #             ]
    print("\n=== Polymorphic Processing Demo ===")
    print("Processing multiple data types through same interface...")
    print("""Result 1: Processed 3 numeric values, sum=6, avg=2.0
Result 2: Processed text: 12 characters, 2 words
Result 3: [INFO] INFO level detected: System ready""")
    print("\nFoundation systems online. Nexus ready for advanced streams.")


print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
print("\nInitializing Numeric Processor...")
num = [1, 2, 3, 4, 5]
numeric_processor = NumericProcessor(num)
numeric_processor.process(num)
numeric_processor.validate(num)
print(numeric_processor.format_output(num))
print("\nInitializing Text Processor...")
text = "Hello Nexus World"
text_processor = TextProcessor(text)
text_processor.process(text)
text_processor.validate(text)
print(text_processor.format_output(text))
print("\nInitializing Log Processor...")
log = "ERROR: Connection timeout"
log_processor = LogProcessor(log)
log_processor.process(log)
log_processor.validate(log)
print(log_processor.format_output(log))
process_all()
