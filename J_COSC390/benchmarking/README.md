---
dataset_info:
  features:
  - name: id
    dtype: string
  - name: question
    dtype: string
  - name: reasoning_chain
    struct:
    - name: final_answer
      dtype: string
    - name: steps
      list:
      - name: explanation
        dtype: string
      - name: is_correct
        dtype: bool
  - name: answer
    dtype: string
  - name: is_correct
    dtype: bool
  splits:
  - name: train
    num_bytes: 38850159
    num_examples: 33081
  download_size: 14827647
  dataset_size: 38850159
configs:
- config_name: default
  data_files:
  - split: train
    path: data/train-*
---
