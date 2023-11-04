SELECT title FROM movies
LEFT JOIN stars on movies.id = stars.movie_id
LEFT JOIN people on people.id = stars.person_id
LEFT JOIN ratings on ratings.movie_id = movies.id
where people.name = 'Chadwick Boseman'
order by ratings.rating desc limit 5;