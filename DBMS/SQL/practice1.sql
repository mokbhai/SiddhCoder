CREATE TABLE mok
(
    id int primary key NOT NULL,
    name varchar(55) NOT NULL
);

CREATE TABLE nok
(
    id int primary key,
    mokid int,
    name varchar(255)
);

INSERT INTO mok VALUES(1, 'mok');
INSERT INTO mok VALUES(2, 'ewf');
INSERT INTO mok VALUES(3, 'sfd');
INSERT INTO mok VALUES(4, 'dsf');


INSERT INTO nok VALUES(1, 1, 'nij');
INSERT INTO nok VALUES(2, 1, 'flnw');
INSERT INTO nok VALUES(3, 2, 'wgnl');
INSERT INTO nok VALUES(4, 3, 'wgenl');


select * from mok;
select * from nok;

select * from mok
join nok on mok.id = nok.mokid;

select * from mok
right join nok on mok.id = nok.mokid;

select * from mok
left join nok on mok.id = nok.mokid;

SELECT nok.id, mok.id as mok_id, mok.name, nok.name as nok_name
FROM mok
INNER JOIN nok ON mok.id = nok.mokid
ORDER BY nok.id DESC;

SELECT nok.id, mok.name || ' ' || nok.name AS fullname, 'id: ' || nok.mokid as mok_id
FROM mok
INNER JOIN nok ON mok.id = nok.mokid
ORDER BY nok.id DESC;

