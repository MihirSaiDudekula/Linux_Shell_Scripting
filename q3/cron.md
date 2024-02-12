The Cron software utility is a time-based job scheduler in Unix-like operating systems. Cron allows Linux and Unix users to run commands or scripts at a given time and date. 

 Installation Steps:

  1. #apt-get update && #apt-get upgrade
  2. #apt-get install cron
  3. #systemctl status cron
  4. #nano /etc/crontab
  5. #crontab -e //install your cron job by running this command.

    crontab -l : List the all your cron jobs.
    crontab -r : Delete the current cron jobs.
