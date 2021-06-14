CREATE database library;
use library;

CREATE TABLE bank_details(
  bank_details_id INT PRIMARY KEY auto_increment,
  account_holder VARCHAR(40) NOT NULL,
  iban VARCHAR(34) NOT NULL UNIQUE,
  account_number VARCHAR(20),
  bank_code VARCHAR(20)
);

CREATE TABLE user_account(
  account_id INT PRIMARY KEY auto_increment,
  bank_details_id INT,
  account_type VARCHAR(20),
  yearly_payment FLOAT,
  CONSTRAINT bank_details
  FOREIGN KEY (bank_details_id) REFERENCES bank_details (bank_details_id)
  ON DELETE CASCADE
  ON UPDATE RESTRICT
);

CREATE TABLE user(
  user_id INT PRIMARY KEY auto_increment,
  account_id INT,
  first_name VARCHAR(20) NOT NULL,
  last_name VARCHAR(20) NOT NULL,
  birthday DATE,
  CONSTRAINT user_account
  FOREIGN KEY (account_id) REFERENCES user_account (account_id)
  ON DELETE CASCADE
  ON UPDATE RESTRICT
);

CREATE TABLE medium(
  medium_id INT PRIMARY KEY auto_increment,
  author VARCHAR(40),
  type VARCHAR(30),
  loan_duration INT,
  title VARCHAR(40),
  usk_fsk VARCHAR(20)
);

CREATE TABLE loans(
  loan_id INT PRIMARY KEY auto_increment,
  user_id INT,
  medium_id INT,
  initial_loan_date DATE,
  return_date DATE,
  CONSTRAINT user
  FOREIGN KEY (user_id) REFERENCES user (user_id)
  ON DELETE CASCADE
  ON UPDATE RESTRICT,
  CONSTRAINT medium
  FOREIGN KEY (medium_id) REFERENCES medium (medium_id)
  ON DELETE CASCADE
  ON UPDATE RESTRICT
);
