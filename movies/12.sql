SELECT distinct title FROM movies
LEFT JOIN stars on movies.id = stars.movie_id
LEFT JOIN people on people.id = stars.person_id
where people.name = 'Jennifer Lawrence'
and movie_id in
(
    SELECT DISTINCT movie_id from stars
    LEFT JOIN people on people.id = stars.person_id
    where people.name = 'Bradley Cooper'
);