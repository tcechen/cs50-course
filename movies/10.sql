SELECT name FROM people
LEFT JOIN directors on people.id = directors.person_id
LEFT JOIN ratings on ratings.movie_id = directors.movie_id
where ratings.rating >= '9';