# c
C Programs:

<h1>Sports Database Overview</h1>
<h3>Language and Framework</h3>
C (Kate)

<h3>Purpose</h3>
A sports database that stores event and athlete information in a Queue ADT.

<h2>Design</h2>
<h3>Events</h3>

Event code (eg. 0, 1, 2, 3, 4, etc.).
Each event code must be unique. There is no limit to the number of events but each code will be greater than or equal

Event name (eg. "Single's figure skating", "Pair skating", "Curling", "Ice hockey", etc.).
Only sports up to 50 characters in length are acceptable (including the null character - So think of this as 49+1)

Athlete/Team/Competitor count (eg. 10, 11, 12, 13, 14, etc.).
Only integers 10-99 are acceptable

Gender (eg. "Men's", "Women's", and "Mixed" represented in your database as 'M', 'W', and 'X' respectively).
Only the characters M, W, and X are acceptable

<h3>Athlete</h3>

Athlete code (eg. 0, 1, 2, 3, 4, etc.)
Each event code must be unique. There is no limit to the number of athletes

Athlete name (eg. "John Smith", "Jane Doe", etc.)
Only names up to 50 characters in length are acceptable (including the null character - So think of this as 49+1)

Athlete age (eg. 16, 17, 18, etc.)
Only integers 16-99 are acceptable

Gender (eg. "Man", "Woman", and "Unidentified" represented in your database as 'M', 'W', and 'X' respectively)
Only the characters M, W, and X are acceptable

Program will then use a linked list of structures to represent all events and a linked list of structures to represent all
athletes.
