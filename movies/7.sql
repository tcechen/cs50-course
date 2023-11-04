select title, rating from movies
inner join ratings on movies.id = ratings.movie_id
and movies.year = '2010'
order by rating desc, title;