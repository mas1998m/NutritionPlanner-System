import React, { useState } from 'react';
import { Container, Row, Col, Card, ListGroup, Table, Carousel, Form, Button } from 'react-bootstrap';

function DietPlan({ plan, onFeedback }) {
  const [feedback, setFeedback] = useState('');
  const mealNames = ["Breakfast", "Snack 1 (Fruit)", "Lunch", "Snack 2 (Sweet)", "Dinner"];

  const handleFeedbackSubmit = (e) => {
      e.preventDefault();
      onFeedback(feedback);
      setFeedback('');
  };

  return (
    <Container fluid className="my-4">
      <Row className="mb-4">
        <Col>
          <h1 className="text-center">Nutritional plan</h1>
        </Col>
      </Row>

      <Row>
        <Col md={4}>
          <Card className="mb-4">
            <Card.Body>
              <Card.Title>Personal Metrics & Data</Card.Title>
              <ListGroup variant="flush">
                <ListGroup.Item>Name: {plan.name}</ListGroup.Item>
                <ListGroup.Item>Age: {plan.age}</ListGroup.Item>
                <ListGroup.Item>Height: {plan.height} cm</ListGroup.Item>
                <ListGroup.Item>Current Weight: {plan.weight} kg</ListGroup.Item>
                <ListGroup.Item>BMI: {plan.BMI.toFixed(2)}</ListGroup.Item>
                <ListGroup.Item>BMR: {plan.BMR.toFixed(2)}</ListGroup.Item>
                <ListGroup.Item>Ideal Weight Range: {plan.lowIdeal.toFixed(2)}~{plan.highIdeal.toFixed(2)}</ListGroup.Item>
                <ListGroup.Item>Advised Water Intake: {plan.waterIntake} ml</ListGroup.Item>
              </ListGroup>
            </Card.Body>
          </Card>
        </Col>

        <Col md={8}>
          <Card className="mb-4">
            <Card.Body>
              <Card.Title>Nutrition Summary</Card.Title>
              <Table striped bordered hover>
                <thead>
                  <tr>
                    <th>Day</th>
                    <th>Total Calories</th>
                    <th>Total Carbs (g)</th>
                    <th>Total Fats (g)</th>
                    <th>Total Protein (g)</th>
                  </tr>
                </thead>
                <tbody>
                  {plan.nutritionSummary.map((item, index) => (
                    <tr key={index}>
                      <td>{index + 1}</td>
                      <td>{item.totalCalories}</td>
                      <td>{item.totalCarbs.toFixed(2)}</td>
                      <td>{item.totalFats.toFixed(2)}</td>
                      <td>{item.totalProtein.toFixed(2)}</td>
                    </tr>
                  ))}
                </tbody>
              </Table>
            </Card.Body>
          </Card>
        </Col>
      </Row>

      <Row>
        <Col md={6}>
          <Card className="mb-4">
            <Card.Body>
              <Card.Title>Meal Plan</Card.Title>
              <Carousel>
                {plan.plan.days.map((day, dayIndex) => (
                  <Carousel.Item key={dayIndex}>
                    <Card>
                      <Card.Header>Day {dayIndex + 1}</Card.Header>
                      <Card.Body>
                        <ListGroup variant="flush">
                          {day.map((meal, mealIndex) => (
                            <ListGroup.Item key={mealIndex}>
                              <strong>{mealNames[mealIndex]}:</strong> {meal.join(", ")}
                            </ListGroup.Item>
                          ))}
                        </ListGroup>
                      </Card.Body>
                    </Card>
                  </Carousel.Item>
                ))}
              </Carousel>
            </Card.Body>
          </Card>
        </Col>

        <Col md={6}>
          <Card className="mb-4">
            <Card.Body>
              <Card.Title>Submit Your Feedback</Card.Title>
              <Form onSubmit={handleFeedbackSubmit}>
                <Form.Group controlId="feedbackForm.ControlTextarea">
                  <Form.Label>Feedback</Form.Label>
                  <Form.Control
                    as="textarea"
                    rows={6}
                    value={feedback}
                    onChange={(e) => setFeedback(e.target.value)}
                    placeholder="Enter your feedback here"
                  />
                </Form.Group>
                <Button variant="primary" type="submit" className="mt-3">
                  Submit
                </Button>
              </Form>
            </Card.Body>
          </Card>
        </Col>
      </Row>
    </Container>
  );
}

export default DietPlan;
