SELECT name FROM people
LEFT JOIN stars on people.id = stars.person_id
LEFT JOIN movies on movies.id = stars.movie_id
where movies.title = 'Toy Story';