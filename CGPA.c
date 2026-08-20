#include <stdio.h>
#include <math.h>

double get_grade_point(double percentage) {
    if (percentage >= 80.0) return 4.00;
    else if (percentage >= 75.0) return 3.75;
    else if (percentage >= 70.0) return 3.50;
    else if (percentage >= 65.0) return 3.25;
    else if (percentage >= 60.0) return 3.00;
    else if (percentage >= 55.0) return 2.75;
    else if (percentage >= 50.0) return 2.50;
    else if (percentage >= 45.0) return 2.25;
    else if (percentage >= 40.0) return 2.00;
    else return 0.00;
}

const char* get_letter_grade(double percentage) {
    if (percentage >= 80.0) return "A+";
    else if (percentage >= 75.0) return "A";
    else if (percentage >= 70.0) return "A-";
    else if (percentage >= 65.0) return "B+";
    else if (percentage >= 60.0) return "B";
    else if (percentage >= 55.0) return "B-";
    else if (percentage >= 50.0) return "C+";
    else if (percentage >= 45.0) return "C";
    else if (percentage >= 40.0) return "D";
    else return "F";
}

int main() {
    int num_courses;
    
    printf("Enter number of courses: ");
    if (scanf("%d", &num_courses) != 1 || num_courses <= 0) {
        printf("Invalid number of courses.\n");
        return 1;
    }

    double total_grade_points = 0.0;

    for (int i = 1; i <= num_courses; i++) {
        double attendance, continuous, mid, final_exam;
        double max_att, max_cont, max_mid, max_final;

        printf("\n================ COURSE %d ================\n", i);

        printf("Enter Maximum Marks for Attendance: ");
        scanf("%lf", &max_att);
        printf("Enter Obtained Marks for Attendance: ");
        scanf("%lf", &attendance);

        printf("Enter Maximum Marks for Continuous Assessment: ");
        scanf("%lf", &max_cont);
        printf("Enter Obtained Marks for Continuous Assessment: ");
        scanf("%lf", &continuous);

        printf("Enter Maximum Marks for Midterm Evaluation: ");
        scanf("%lf", &max_mid);
        printf("Enter Obtained Marks for Midterm Evaluation: ");
        scanf("%lf", &mid);

        printf("Enter Maximum Marks for Final Evaluation: ");
        scanf("%lf", &max_final);
        printf("Enter Obtained Marks for Final Evaluation: ");
        scanf("%lf", &final_exam);

        double total_max_marks = max_att + max_cont + max_mid + max_final;
        
        if (total_max_marks <= 0) {
            printf("Invalid maximum marks sum.\n");
            return 1;
        }

        double obtained_total = round(attendance) + round(continuous) + round(mid) + round(final_exam);
        double percentage = (obtained_total / total_max_marks) * 100.0;
        double gp = get_grade_point(percentage);
        const char* grade = get_letter_grade(percentage);

        printf("\nCourse %d Summary:\n", i);
        printf("Obtained Marks: %.0f / %.0f (%.2f%%)\n", obtained_total, total_max_marks, percentage);
        printf("Grade: %s | Grade Point: %.2f\n", grade, gp);

        total_grade_points += gp;
    }

    double average_gpa = total_grade_points / num_courses;
    printf("\n========================================\n");
    printf("TOTAL COURSES: %d\n", num_courses);
    printf("AVERAGE GPA / CGPA: %.2f\n", average_gpa);
    printf("========================================\n");

    return 0;
}