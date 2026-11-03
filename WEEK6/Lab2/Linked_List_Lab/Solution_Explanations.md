# Solution Explanations for the Instructor

## 1. Appending and counting
A new node is created. If the list is empty, the head pointer is set to this node. Otherwise, we walk to the last node and link the last node's next field to the new node. When counting, each node is visited once.

Using `Node **head` allows the function to modify the caller's head pointer. Since counting only reads the list, `const Node *` is sufficient. Appending takes O(n) time and counting takes O(n) time; apart from the new node, extra space is O(1).

## 2. Search
The position starts at 0. At each node the value is compared. On the first match the position is returned immediately; if the end is reached, -1 is returned. This way the first position of repeated values is found. Worst case is O(n) time and O(1) extra space.

## 3. Deletion
`current` holds the candidate node and `previous` holds the node before it. If there is no match, 0 is returned. If the head is being deleted, `*head` is moved to the node after the one being deleted. Otherwise, `previous->next` is set to `current->next`. After the link is fixed, current is freed. The freed node is never accessed again. Worst case is O(n) time and O(1) extra space.

## 4. Reversal
`previous` holds the head of the already-reversed part, and `current` holds the next node to process. First, the original next node is saved in `next`; then current->next is pointed backwards. The pointers are advanced. At the end of the loop, previous is the new head. If we did not save the next node beforehand, we would lose access to the rest of the list. O(n) time, O(1) extra space.

## Expected program output

### 01_append_count

```text
NULL
Count: 0
10 -> 20 -> 30 -> NULL
Count: 3
```

### 02_search

```text
Empty search: -1
10 -> 20 -> 30 -> 20 -> NULL
Find 10: 0
Find 20: 1
Find 99: -1
```

### 03_delete_first

```text
Delete from empty: 0
10 -> 20 -> 30 -> 20 -> NULL
Delete 20: 1
10 -> 30 -> 20 -> NULL
Delete 10: 1
30 -> 20 -> NULL
Delete 20: 1
30 -> NULL
Delete 99: 0
30 -> NULL
Delete 30: 1
NULL
```

### 04_reverse

```text
NULL
10 -> NULL
10 -> 20 -> 30 -> 40 -> NULL
40 -> 30 -> 20 -> 10 -> NULL
10 -> 20 -> 30 -> 40 -> NULL
```
