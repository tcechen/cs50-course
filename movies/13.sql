select name from people where id in (
    select person_id from stars
    where movie_id in (
        SELECT movie_id FROM movies
        LEFT JOIN stars on movies.id = stars.movie_id
        LEFT JOIN people on people.id = stars.person_id
        where people.name = 'Kevin Bacon' and people.birth = '1958'
    )
)
and name != 'Kevin Bacon';