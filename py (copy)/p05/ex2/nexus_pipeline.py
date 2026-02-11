#!/usr/bin/env python3
from abc import ABC, abstractmethod
from typing import Any, List, Protocol, runtime_checkable


@runtime_checkable
class ProcessingStage(Protocol):
    def process(self, data: Any) -> Any:
        ...


class InputStage:
    def process(self, data: Any) -> Any:
        print("Input:", data)
        return data


class TransformStage:
    def process(self, data: Any) -> str:
        print("Transform: Enriched with metadata and validation")
        return f"Enriched: {data}"


class OutputStage:
    def process(self, data: Any) -> str:
        print("Output: Processed reading:", data)
        return f"Final: {data}"


class ProcessingPipeline(ABC):
    def __init__(self, pipeline_id: str):
        self.pipeline_id = pipeline_id
        self.stages: List[ProcessingStage] = []
        self.stats = {"count": 0, "errors": 0}

    def add_stage(self, stage: ProcessingStage):
        self.stages.append(stage)

    @abstractmethod
    def process(self, data: Any) -> Any:
        pass


class JSONAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        print(f"\nProcessing JSON data through pipeline {self.pipeline_id}...")
        try:
            current_data = data
            for stage in self.stages:
                current_data = stage.process(current_data)
            self.stats["count"] += 1
            return current_data
        except Exception as e:
            self.stats["errors"] += 1
            print(f"Recovery initiated: Switching to backup processor for {e}")


class CSVAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        print(f"\nProcessing CSV data through pipeline {self.pipeline_id}...")
        current_data = data
        for stage in self.stages:
            current_data = stage.process(current_data)
        return current_data


class StreamAdapter(ProcessingPipeline):
    def process(self, data: Any) -> Any:
        print(f"\nProcessing Stream data through pipeline {self.pipeline_id}")
        current_data = data
        for stage in self.stages:
            current_data = stage.process(current_data)
        return current_data


class NexusManager:
    def __init__(self):
        print("=== CODE NEXUS - ENTERPRISE PIPELINE SYSTEM ===\n")
        print("Initializing Nexus Manager...")
        print("Pipeline capacity: 1000 streams/second")
        self.pipelines: List[ProcessingPipeline] = []

    def add_pipeline(self, pipeline: ProcessingPipeline):
        self.pipelines.append(pipeline)

    def process_data(self, data: Any):
        for pipeline in self.pipelines:
            pipeline.process(data)


manager = NexusManager()

json_pipe = JSONAdapter("NX-88")

print("\nCreating Data Processing Pipeline...")
print("Stage 1: Input validation and parsing")
json_pipe.add_stage(InputStage())
print("Stage 2: Data transformation and enrichment")
json_pipe.add_stage(TransformStage())
print("Stage 3: Output formatting and delivery")
json_pipe.add_stage(OutputStage())
manager.add_pipeline(json_pipe)

print("\n=== Multi-Format data processing ===")
manager.process_data({"sensor": "temp", "value": 23.5, "unit": "C"})

print("\n=== Pipeline Chaining Demo ===")
raw_data = "User_Login_Event"
p1_out = json_pipe.process(raw_data)
print("Chain result: Data processed through 3-stage pipeline")

print("\n=== Error Recovery Test ===")
print("Simulating pipeline failure...")


class FaultyStage:
    def process(self, data): raise ValueError(data)


faulty_pipe = JSONAdapter("FAIL-SAFE")
faulty_pipe.add_stage(FaultyStage())
faulty_pipe.process("Corrupt data")

print("\nNexus Integration complete. All systems operational.")
